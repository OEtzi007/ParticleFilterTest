/*
 * robotintelligence.h
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#ifndef ROBOTINTELLIGENCE_H_
#define ROBOTINTELLIGENCE_H_

#include <vector>

#include "lasersensorinterface.h"
#include "motoractuatorinterface.h"
#include "timeinterface.h"
#include "simulatedtestrobot.h"
#include "map.h"

struct Particle{
	double x, y;
	double ori;
	double weight;
};

class RobotIntelligence {
private:
	LaserSensorInterface &laserData;
	MotorActuatorInterface &motorData;
	TimeInterface &timeData;

    Map map;
	std::vector<Particle> particles;
    SimulatedTestRobot myFriend;

	void run();
	void initParticles();
	std::vector<double> readSensors();
	void evalSensors();
	void resampling();
	void estimatePosition();
	void calcSigma();
	void move();
	void moveParticles(const double);
	double random();
	double random(const double, const double);
	double gaussian(const double, const double, const double);
public:
	RobotIntelligence(LaserSensorInterface&, MotorActuatorInterface&, TimeInterface&);
	virtual ~RobotIntelligence();
	void startRobot();
	void stopRobot();
};

#endif /* ROBOTINTELLIGENCE_H_ */
