/*
 * robotintelligence.cpp
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#include "robotintelligence.h"

#include <random>
#include <cassert>
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
		double curTime=timeData->getData("time");
		double timeStep = curTime-lastTime;
		lastTime = curTime;
		moveParticles(timeStep);
		evalSensors();

		estimatePosition(); //TODO returnValue
		calcSigma(); //TOOD returnValue
		resampling();

		move();
	}
}

void RobotIntelligence::evalSensors()
{
	std::vector<double> sensorData(laserData->getAllData());
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle &curParticle = particles[i];
		simulatedRobot.set(curParticle.x, curParticle.y, curParticle.ori);
		std::vector<double> particleDistances = simulatedRobot.getNonErrorDistances();
		for(unsigned int j=0; j<sensorData.size(); j++) {
			curParticle.weight *= gaussian(sensorData[j], particleDistances[j], LaserSensor::relSigmaL*particleDistances[j]);
		}
	}
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
	double highestWeight = -1;
	Particle bestParticle; // after for-loop this represents the robot's most likely position
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		if (particles[i].weight > highestWeight) {
			highestWeight = particles[i].weight;
			bestParticle = particles[i];
		}
	}
#ifdef DEBUG
	std::cout << "Robot thinks at time " << timeData->getData("time") << ":\tx=" << bestParticle.x << "\ty=" << bestParticle.y << "\tori=" << bestParticle.ori << std::endl;
#endif
}

double RobotIntelligence::calcSigma() const
{
	double totalWeight=0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		totalWeight += particles[i].weight;
	}

	double x_mean = 0;
	double y_mean = 0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		x_mean += particles[i].weight*particles[i].x;
		y_mean += particles[i].weight*particles[i].y;
	}
	x_mean /= totalWeight;
	y_mean /= totalWeight;

	double x_sigma_squared = 0;
	double y_sigma_squared = 0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		x_sigma_squared += particles[i].weight * (particles[i].x-x_mean)*(particles[i].x-x_mean);
		y_sigma_squared += particles[i].weight * (particles[i].y-y_mean)*(particles[i].y-y_mean);
	}
	x_sigma_squared /= totalWeight;
	y_sigma_squared /= totalWeight;

	double totalSigma = std::sqrt(x_sigma_squared+y_sigma_squared);

	return totalSigma;
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
		double delx=cos(curParticle.ori)*s_x;
		double dely=sin(curParticle.ori)*s_x;
		delx-=sin(curParticle.ori)*s_y;
		dely+=cos(curParticle.ori)*s_y;
		curParticle.x+=delx;
		curParticle.y+=dely;
		curParticle.ori+=omega(RANDOM_ENGINE)*timeStep;
		while(curParticle.ori >= 2*PI) { //modulo function for double's
			curParticle.ori -= 2*PI;
		}
	}
}

void RobotIntelligence::initParticles()
{
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle;
		curParticle.x=random(0,map.width)+map.base.x;
		curParticle.y=random(0,map.height)+map.base.y;
		curParticle.ori=random(0,2*PI);
		curParticle.weight=1;
		particles.push_back(curParticle);
	}
}

double RobotIntelligence::random(const double& lower_bound, const double& upper_bound) const
{
	std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	return unif(RANDOM_ENGINE);
}

double RobotIntelligence::gaussian(const double& x, const double& mean, const double& sigma) const
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
	return std::exp(expNumerator/expDenominator)/(sigma*std::sqrt(2*PI));
}

void RobotIntelligence::reset(Interfaces& interfaces)
{
	laserData=&interfaces.laserSensorI;
	motorData=&interfaces.motorActuatorI;
	timeData=&interfaces.timeI;
}
