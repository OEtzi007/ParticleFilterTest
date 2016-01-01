/*
 * robotintelligence.h
 *
 *  Created on: 28.12.2015
 *      Author: Marvin
 */

#ifndef ROBOTINTELLIGENCE_H_
#define ROBOTINTELLIGENCE_H_

#include <QThread>
#include <vector>

#include "interface.h"
#include "simulatedtestrobot.h"
#include "map.h"

struct Particle{
	double x, y;
	double ori;
	double weight;
};

class RobotIntelligence : public QThread {
private:
	Interface* laserData;
	Interface* motorData;
	Interface* timeData;

	Map map;
	std::vector<Particle> particles;
	SimulatedTestRobot myFriend;

	void run() Q_DECL_OVERRIDE ;
	void initParticles();
	std::vector<double> readSensors();
	void evalSensors();
	void resampling();
	void estimatePosition();
	double calcSigma() const;
	void move();
	void moveParticles(const double);
	double random();
	double random(const double, const double);
	double gaussian(const double, const double, const double);
public:
	RobotIntelligence(Interfaces&);
	virtual ~RobotIntelligence();
	void startRobot();
	void stopRobot();
	void reset(Interfaces&);
};

#endif /* ROBOTINTELLIGENCE_H_ */
