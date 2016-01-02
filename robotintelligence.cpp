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
{
	initParticles();
	double lastTime = timeData->getData("time");
	//TODO laserDatafrequence
	while(true) {
		double timeStep = timeData->getData("time")-lastTime;
		lastTime = timeData->getData("time");
		moveParticles(timeStep);
		evalSensors();

		estimatePosition(); //TODO returnValue
		calcSigma(); //TODO returnValue
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

void RobotIntelligence::resampling()
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
				newParticles.push_back(Particle(particles[j]));
				newParticles[newParticles.size()-1].weight = 1;
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
	double highestWeight = 0;
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
		x_sigma_squared += particles[i].weight * std::pow(particles[i].x-x_mean, 2);
		y_sigma_squared += particles[i].weight * std::pow(particles[i].y-y_mean, 2);
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
		curParticle.ori=curParticle.ori+omega(RANDOM_ENGINE)*timeStep;
		while(curParticle.ori >= 2*PI) { //modulo function for double's
			curParticle.ori -= 2*PI;
		}
	}
}

void RobotIntelligence::initParticles()
{
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle;
		curParticle.x=random()*map.width+map.base.x;
		curParticle.y=random()*map.height+map.base.y;
		curParticle.ori=random()*2*PI;
		curParticle.weight=1;
		particles.push_back(curParticle);
	}
}

double RobotIntelligence::random()
{
	double lower_bound = 0;
	double upper_bound = 1;
	std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	return unif(RANDOM_ENGINE);
}

double RobotIntelligence::random(const double& lower_bound, const double& upper_bound)
{
	std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	return unif(RANDOM_ENGINE);
}

double RobotIntelligence::gaussian(const double& x, const double& mean, const double& sigma)
{
	if(sigma == 0)
		return x==mean ? 1 : 0;
	double expNumerator = -std::pow(2, x-mean);
	double expDenominator = 2* std::pow(2, sigma);
	return std::exp(expNumerator/expDenominator)/(sigma*std::sqrt(2*PI));
}

void RobotIntelligence::reset(Interfaces& interfaces)
{
	laserData=&interfaces.laserSensorI;
	motorData=&interfaces.motorActuatorI;
	timeData=&interfaces.timeI;
}
