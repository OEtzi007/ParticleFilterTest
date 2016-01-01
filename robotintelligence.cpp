/*
 * robotintelligence.cpp
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#include "robotintelligence.h"

#include <random>
#include "constants.h"
#include "map.h"

RobotIntelligence::RobotIntelligence(LaserSensorInterface &laserData, MotorActuatorInterface &motorData, TimeInterface &timeData):laserData(laserData), motorData(motorData), timeData(timeData) {
}

RobotIntelligence::~RobotIntelligence() {
}

void RobotIntelligence::run() {
	initParticles();
	while(true) {
		std::vector<double> sensorData = readSensors();
		evalSensors(sensorData);
		resampling();

		estimatePosition();
		move();

		moveParticles();
	}
}

std::vector<double> RobotIntelligence::readSensors() {
	return std::vector<double>(laserData.getSensorData());
}

void RobotIntelligence::evalSensors(std::vector<double> sensorData) {
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle = particles.at(i);
	}
}

void RobotIntelligence::resampling() {
	double totalWeight=0;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		totalWeight += particles.at(i).weight;
	}

	std::vector<Particle> newParticles;
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {  //one new Particle per loop
		double curRand = random(0.0, totalWeight); //Random number between 0 and totalWeight to determine the copied Particle
		double curWeight = 0;
		for(unsigned int j=0; j<NUM_PARTICLES; j++) { //check for every Particle if it should copy
			curWeight += particles.at(j).weight;
			if(curRand <= curWeight) {
				newParticles.push_back(particles[j]);
				newParticles.at(newParticles.size()).weight = 1;
				break;
			}
		}
	}
	particles = newParticles;
}

void RobotIntelligence::estimatePosition() {

}

void RobotIntelligence::move() {

}

void RobotIntelligence::moveParticles() {

}

void RobotIntelligence::initParticles() {
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle;
		curParticle.x=random()*Map::width+Map::origin.x;
		curParticle.y=random()*Map::height+Map::origin.y;
		curParticle.ori=random()*2*PI;
		curParticle.weight=1;
		particles.push_back(curParticle);
	}
}

double RobotIntelligence::random() {
	   double lower_bound = 0;
	   double upper_bound = 1;
	   std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	   std::default_random_engine re;
	   return unif(re);
}

double RobotIntelligence::random(double lower_bound, double upper_bound) {
	std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	std::default_random_engine re;
	return unif(re);
}
