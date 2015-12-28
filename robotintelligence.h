/*
 * robotintelligence.h
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#ifndef ROBOTINTELLIGENCE_H_
#define ROBOTINTELLIGENCE_H_

#include <vector>

struct Particle{
	double x, y;
	double ori;
	double weight;
};

class RobotIntelligence {
private:
	LaserSensorInterface laserData;
	MotorInterface motorData;
	TimeInterface timeData;
	std::vector<Particle> particles;

	void run();
	void initParticles();
	void readSensors();
	void evalSensors();
	void resampling();
	void estimatePosition();
	void move();
	void moveParticles();
	double random();
public:
	RobotIntelligence();
	virtual ~RobotIntelligence();
	void startRobot();
	void stopRobot();
};

#endif /* ROBOTINTELLIGENCE_H_ */