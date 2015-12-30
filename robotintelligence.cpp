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

RobotIntelligence::RobotIntelligence(LaserSensorInterface &laserData, MotorActuatorInterface &motorData, TimeInterface &timeData):laserData(laserData), motorData(motorData), timeData(timeData), myFriend(SimulatedTestRobot(&map.base, Coordinate(&map.base)))
{
}

RobotIntelligence::~RobotIntelligence() {
	// TODO Auto-generated destructor stub
}

void RobotIntelligence::run() {
	initParticles();
    double lastTime = timeData.getTime();
    unsigned int lastMeasurementId = laserData.getMeasurementId()-1;
	while(true) { //TODO
        if(lastMeasurementId == laserData.getMeasurementId())
            continue;

        lastMeasurementId = laserData.getMeasurementId();
        double timeStep = timeData.getTime()-lastTime;
        lastTime = timeData.getTime();
        moveParticles(timeStep);
		evalSensors();

        estimatePosition();
		resampling();

		move();
	}
}

std::vector<double> RobotIntelligence::readSensors() {
	return std::vector<double>(laserData.getSensorData()); //TODO wird Kopie angelegt?
}

void RobotIntelligence::evalSensors() {
	std::vector<double> sensorData = readSensors();
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
        Particle &curParticle = particles.at(i);
        myFriend.set(curParticle.x, curParticle.y, curParticle.ori);
        std::vector<double> particleDistances = myFriend.getNonErrorDistances();
        for(unsigned int j=0; j<sensorData.size(); j++) {
            curParticle.weight *= gaussian(sensorData[j], particleDistances[j], LaserSensorInterface::relSigmaL*particleDistances[j]);
        }
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
				newParticles.push_back(Particle(particles.at(j))); //TODO wird kopiert oder referenz uebergeben?
				newParticles.at(newParticles.size()).weight = 1;
				break;
			}
		}
	}
	particles = newParticles;
}

void RobotIntelligence::estimatePosition() { //TODO rethink function, highestWeight best approximation?
	double highestWeight = 0;
	Particle bestParticle; // after for-loop this represents the robot's most likely position
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		if (particles.at(i).weight > highestWeight) {
			highestWeight = particles.at(i).weight;
			bestParticle = particles.at(i);
		}
	}
}

void RobotIntelligence::move() {

}

void RobotIntelligence::moveParticles(double timeStep) {
    std::normal_distribution<double> v_x(motorData.getVelocity().x, MotorActuatorInterface::relSigmaV*motorData.getVelocity().x);
    std::normal_distribution<double> v_y(motorData.getVelocity().y, MotorActuatorInterface::relSigmaV*motorData.getVelocity().y);
    std::normal_distribution<double> omega(motorData.getOmega(), MotorActuatorInterface::sigmaOmega);
    std::default_random_engine re;
    for(int i=0; i<NUM_PARTICLES; i++) {
        Particle &curParticle = particles[i];
        double s_x = v_x(re)*timeStep;
        double s_y = v_y(re)*timeStep;
        double delx=cos(curParticle.ori)*s_x;
        double dely=sin(curParticle.ori)*s_x;
        delx-=sin(curParticle.ori)*s_y;
        dely+=cos(curParticle.ori)*s_y;
        curParticle.x+=delx;
        curParticle.y+=dely;
        curParticle.ori=curParticle.ori+omega(re)*timeStep;
        while(curParticle.ori >= 2*PI) { //modulo function for double's
            curParticle.ori -= 2*PI;
        }
    }
}

void RobotIntelligence::initParticles() {
	for(unsigned int i=0; i<NUM_PARTICLES; i++) {
		Particle curParticle;
        curParticle.x=random()*map.width+map.base.x;
        curParticle.y=random()*map.height+map.base.y;
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

double RobotIntelligence::gaussian(double x, double mean, double sigma) {
    if(sigma == 0)
        return x==mean ? 1 : 0;
    double expNumerator = -std::pow(2, x-mean);
    double expDenominator = 2* std::pow(2, sigma);
    return std::exp(expNumerator/expDenominator)/(sigma*std::sqrt(2*PI));
}
