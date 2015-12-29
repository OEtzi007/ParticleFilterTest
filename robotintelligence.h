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
	std::vector<Particle> particles;

	void run();
	void initParticles();
	std::vector<double> readSensors();
	void evalSensors();
	void resampling();
	void estimatePosition();
	void move();
    void moveParticles(double);
	double random();
	double random(double, double);
public:
	RobotIntelligence(LaserSensorInterface&, MotorActuatorInterface&, TimeInterface&);
	virtual ~RobotIntelligence();
	void startRobot();
	void stopRobot();
};

#endif /* ROBOTINTELLIGENCE_H_ */
