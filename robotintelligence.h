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
	double phi;
	double weight;
};

class RobotIntelligence : public QThread {
private:
	Interface* laserData;
	Interface* motorData;
	Interface* timeData;

	Map map;
	std::vector<Particle> particles;
	Particle estimatedPosition;
	Particle estimationError;
	Particle particleDensityAtEstimatedPosition;
	SimulatedTestRobot simulatedRobot;

	void run() Q_DECL_OVERRIDE ;
	void initParticles();
	std::vector<double> readSensors();
	void evalSensors();
	void resampling();
	void estimatePosition();
	void calcEstimationErrors();
	void move();
	void moveParticles(const double& timeStep);
	double random(const double& lower_bound, const double& upper_bound) const;
	double log_gaussian(const double& x, const double& mean, const double& sigma) const;
public:
	bool isRunning;
	bool quit;

	RobotIntelligence(Interfaces& interfaces);
	virtual ~RobotIntelligence();
	void reset(Interfaces& interfaces);
};

#endif /* ROBOTINTELLIGENCE_H_ */
