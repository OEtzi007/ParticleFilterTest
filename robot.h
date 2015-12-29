#ifndef ROBOT_H
#define ROBOT_H

#include "sphere.h"

#include <vector>
#include "constants.h"

class LaserSensor;

class Robot : public Sphere
{
private:
	std::vector<LaserSensor> laserSensors;
public:
	Robot(CoordinateSystem* const, const Coordinate&, const double& radius=ROBOT_RADIUS, const std::string& laserConfigFile=LASER_CONFIG_FILE);
};

#endif // ROBOT_H
