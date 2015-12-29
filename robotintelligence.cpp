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

RobotIntelligence::RobotIntelligence() {
	// TODO Auto-generated constructor stub

}

RobotIntelligence::RobotIntelligence(LaserSensorInterface &laserData, MotorInterface &motorData, TimeInterface &timeData):laserData(laserData), motorData(motorData), timeData(timeData) {
}

RobotIntelligence::~RobotIntelligence() {
	// TODO Auto-generated destructor stub
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
	return std::vector<double>(laserData.getSensorData()); //TODO wird Kopie angelegt?
}

void RobotIntelligence::evalSensors(std::vector<double> sensorData) {
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle = particles.at(i);

	}
}

void RobotIntelligence::resampling() {

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
		curParticle.x=random()*Map::width+Map::origin.getX();
		curParticle.y=random()*Map::height+Map::origin.getY();
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
