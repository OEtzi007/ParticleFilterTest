/*
 * robotintelligence.cpp
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#include "robotintelligence.h"

#include <random>
#include "constants.h"

RobotIntelligence::RobotIntelligence() {
	// TODO Auto-generated constructor stub

}

RobotIntelligence::~RobotIntelligence() {
	// TODO Auto-generated destructor stub
}

void RobotIntelligence::run() {
	initParticles();
	while(true) {
		std::vector<double> sensorData = readSensors();
		evalSensors();
		resampling();

		estimatePosition();
		move();

		moveParticles();
	}
}

void RobotIntelligence::evalSensors() {
	for(int i=0; i<NUM_PARTICLES; i++) {

	}
}

void RobotIntelligence::initParticles() {
	for(int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle;
		curParticle.x=random()*Map::width;
		curParticle.y=random()*Map::heigth;
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
