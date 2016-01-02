/*
 * robotintelligence.cpp
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#include "robotintelligence.h"

#include <random>
#include <cassert>
#include <limits>
#include "constants.h"
#include "map.h"
#include "motoractuator.h"

RobotIntelligence::RobotIntelligence(Interfaces& interfaces):
	laserData(&interfaces.laserSensorI),
	motorData(&interfaces.motorActuatorI),
	timeData(&interfaces.timeI),
	simulatedRobot(SimulatedTestRobot(&map,
									  &map.base,
									  Coordinate(&map.base)))
{
}

RobotIntelligence::~RobotIntelligence()
{
}

void RobotIntelligence::run()
{	//TODO move into one methode particleFilter
	initParticles();
	double lastTime = timeData->getData("time");
	//TODO laserDatafrequence
	while(true) {
		estimatePosition();
		move();

		evalSensors();
		resampling();

		double curTime=timeData->getData("time");
		double timeStep = curTime-lastTime;
		lastTime = curTime;

		moveParticles(timeStep);
	}
}
#include <iostream>	//TODO remove
void RobotIntelligence::evalSensors()
{
	std::vector<double> sensorData(laserData->getAllData());
	std::vector<double> log_gaussians;
	double max_log_gaussians=-std::numeric_limits<double>::max();
	for(unsigned int i=0; i<NUM_PARTICLES; ++i) {
		simulatedRobot.set(particles[i].x, particles[i].y, particles[i].phi);
		std::vector<double> particleDistances = simulatedRobot.getNonErrorDistances();
		double cur_log_gaussians=std::log(particles[i].weight);
		for(unsigned int j=0; j<sensorData.size(); ++j) {
			cur_log_gaussians += log_gaussian(sensorData[j],
											  particleDistances[j],
											  LaserSensor::relSigmaL*particleDistances[j]);
		}
		log_gaussians.push_back(cur_log_gaussians);
		if(max_log_gaussians<cur_log_gaussians)
			max_log_gaussians=cur_log_gaussians;
	}
	double sum_weights=0;
	for(unsigned int i=0;i<NUM_PARTICLES;++i){
		particles[i].weight=std::exp(log_gaussians[i]-max_log_gaussians);
		sum_weights+=particles[i].weight;
	}
	std::vector<double> weights;	//TODO remove
	for(unsigned int i=0;i<NUM_PARTICLES;++i){
		particles[i].weight/=sum_weights;
		weights.push_back(particles[i].weight);
	}
	/*
	std::sort(weights.rbegin(),weights.rend());	//TODO remove
	for(unsigned int i=0;i<NUM_PARTICLES;++i){
		std::cout << weights[i] << "\t";	//TODO remove
	}
	std::cout << std::endl;	//TODO remove
	*/
}

void RobotIntelligence::resampling() //TODO implement more efficient (resampling wheel)
{
	double totalWeight=0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		totalWeight += particles[i].weight;
	}

	std::vector<Particle> newParticles;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {  //one new Particle per loop
		double curRand = random(0.0, totalWeight); //Random number between 0 and totalWeight to determine the copied Particle
		double curWeight = 0;
		for(unsigned int j=0; j<NUM_PARTICLES; j++) { //check for every Particle if it should copy
			curWeight += particles[j].weight;
			if(curRand <= curWeight) {
				newParticles.push_back(particles[j]);
				newParticles.back().weight=1;
				break;
			}
		}
	}
	particles = newParticles;
}

#ifdef DEBUG
#include <iostream>
#endif
void RobotIntelligence::estimatePosition()
{ //TODO rethink function, highestWeight best approximation?
	estimatedPosition = particles[0]; // after for-loop this represents the robot's most likely position
	for(unsigned int i=1; i<NUM_PARTICLES; i++) {
		if (particles[i].weight > estimatedPosition.weight) {
			estimatedPosition = particles[i];
		}
	}
	calcEstimationErrors();
#ifdef DEBUG
	std::cout << "Robot thinks at time " << timeData->getData("time") <<
				 ":\tx=" << estimatedPosition.x << "+-" << estimationError.x <<
				 "\ty=" << estimatedPosition.y << "+-" << estimationError.y <<
				 "\tori=" << estimatedPosition.phi << "+-" << estimationError.phi << std::endl;
#endif
}

void RobotIntelligence::calcEstimationErrors()
{
	double totalWeight=0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		totalWeight += particles[i].weight;
	}

	double x_mean = 0;
	double y_mean = 0;
	double phi_mean = 0;
	double cos_phi_mean=0;
	double sin_phi_mean=0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		x_mean += particles[i].weight*particles[i].x;
		y_mean += particles[i].weight*particles[i].y;
		cos_phi_mean += particles[i].weight*cos(particles[i].phi);
		sin_phi_mean += particles[i].weight*sin(particles[i].phi);
	}
	x_mean /= totalWeight;
	y_mean /= totalWeight;
	phi_mean = atan2(sin_phi_mean,cos_phi_mean);

	double x_sigma_squared = 0;
	double y_sigma_squared = 0;
	double phi_sigma_squared = 0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		x_sigma_squared += particles[i].weight * (particles[i].x-x_mean)*(particles[i].x-x_mean);
		y_sigma_squared += particles[i].weight * (particles[i].y-y_mean)*(particles[i].y-y_mean);
		double cur_phi_err=particles[i].phi-phi_mean;
		while(cur_phi_err>=PI)
			cur_phi_err-=2*PI;
		while(cur_phi_err<-PI)
			cur_phi_err+=2*PI;
		phi_sigma_squared += particles[i].weight * cur_phi_err*cur_phi_err;
	}
	x_sigma_squared /= totalWeight;
	y_sigma_squared /= totalWeight;
	phi_sigma_squared /= totalWeight;

	estimationError.x=std::sqrt(x_sigma_squared);
	estimationError.y=std::sqrt(y_sigma_squared);
	estimationError.phi=std::sqrt(phi_sigma_squared);
	estimationError.weight=1;	//NOTE not relevant
}

void RobotIntelligence::move()
{
}

void RobotIntelligence::moveParticles(const double& timeStep)
{
	std::normal_distribution<double> v_x(motorData->getData("vx"), MotorActuator::relSigmaV*motorData->getData("vx"));
	std::normal_distribution<double> v_y(motorData->getData("vy"), MotorActuator::relSigmaV*motorData->getData("vy"));
	std::normal_distribution<double> omega(motorData->getData("omega"), MotorActuator::relSigmaOmega*motorData->getData("omega"));
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle &curParticle = particles[i];
		double s_x = v_x(RANDOM_ENGINE)*timeStep;
		double s_y = v_y(RANDOM_ENGINE)*timeStep;
		double delx=cos(curParticle.phi)*s_x;
		double dely=sin(curParticle.phi)*s_x;
		delx-=sin(curParticle.phi)*s_y;
		dely+=cos(curParticle.phi)*s_y;
		curParticle.x+=delx;
		curParticle.y+=dely;
		curParticle.phi+=omega(RANDOM_ENGINE)*timeStep;

		//add random error so that particles are diverse even if there is no movement
		double xerr=estimationError.x/2.;
		double yerr=estimationError.y/2.;
		double phierr=estimationError.phi/2.;
		/*
		if(xerr<0.001)
			xerr=0.001;
		if(yerr<0.001)
			yerr=0.001;
		if(phierr<2*PI/1000)
			phierr=2*PI/1000;
		*/
		curParticle.x=std::normal_distribution<double>(curParticle.x,xerr)(RANDOM_ENGINE);
		curParticle.y=std::normal_distribution<double>(curParticle.y,yerr)(RANDOM_ENGINE);
		curParticle.phi=std::normal_distribution<double>(curParticle.phi,phierr)(RANDOM_ENGINE);

		while(curParticle.phi >= 2*PI) { //modulo function for double's
			curParticle.phi -= 2*PI;
		}
		while(curParticle.phi < 0)
			curParticle.phi += 2*PI;
	}
}

void RobotIntelligence::initParticles()
{
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle;
		curParticle.x=random(0,map.width)+map.base.x;
		curParticle.y=random(0,map.height)+map.base.y;
		curParticle.phi=random(0,2*PI);
		curParticle.weight=1;
		particles.push_back(curParticle);
	}
}

double RobotIntelligence::random(const double& lower_bound, const double& upper_bound) const
{
	std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	return unif(RANDOM_ENGINE);
}

double RobotIntelligence::log_gaussian(const double& x, const double& mean, const double& sigma) const
{
#ifdef DEBUG
	assert(sigma != 0);	//NOTE assert
#endif
	/*
	if(sigma == 0)
		return x==mean ? 1 : 0;
	*/
	double expNumerator = -(x-mean)*(x-mean);
	double expDenominator = 2*sigma*sigma;
	double log_gauss=expNumerator/expDenominator-std::log(sigma*sigma*2*PI)/2;
	return log_gauss;
}

void RobotIntelligence::reset(Interfaces& interfaces)
{
	laserData=&interfaces.laserSensorI;
	motorData=&interfaces.motorActuatorI;
	timeData=&interfaces.timeI;
}
