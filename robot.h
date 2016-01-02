#ifndef ROBOT_H
#define ROBOT_H

#include "sphere.h"

#include <vector>
#include "constants.h"

#include "lasersensor.h"
#include "interface.h"

class Robot : public Sphere
{
protected:
	std::vector<LaserSensor> laserSensors;
public:
	Robot(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin, const double& radius=ROBOT_RADIUS, const std::string& laserConfigFile=LASER_CONFIG_FILE);
	void move(Interface& actuatorInterface);
	void updateSensors(Interface& sensorInterface) const;
};

#endif // ROBOT_H
