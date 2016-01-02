#ifndef SIMULATEDTESTROBOT_H
#define SIMULATEDTESTROBOT_H

#include "robot.h"

class SimulatedTestRobot : public Robot
{
public:
	SimulatedTestRobot(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin, const double& radius=ROBOT_RADIUS, const std::string& laserConfigFile=LASER_CONFIG_FILE);

	std::vector<double> getNonErrorDistances() const; //FIXME distances from laser sensors return
	void set(const double& x, const double& y, const double& phi);
};

#endif // SIMULATEDTESTROBOT_H
