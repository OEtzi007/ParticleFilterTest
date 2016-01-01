#ifndef ROBOT_H
#define ROBOT_H

#include "sphere.h"

#include <vector>
#include "constants.h"

#include "lasersensor.h"
#include "interface.h"

class Robot : public Sphere
{
private:
	std::vector<LaserSensor> laserSensors;
public:
	Robot(World* const, const CoordinateSystem* const, const Coordinate&, const double& radius=ROBOT_RADIUS, const std::string& laserConfigFile=LASER_CONFIG_FILE);
	void move(Interface&);
	void updateSensors(Interface&) const;
};

#endif // ROBOT_H
