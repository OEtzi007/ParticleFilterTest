#ifndef ROBOT_H
#define ROBOT_H

#include "sphere.h"

#include <vector>
#include "constants.h"

#include "lasersensor.h"

class Robot : public Sphere
{
private:
	std::vector<LaserSensor> laserSensors;
public:
	Robot(CoordinateSystem* const, const Coordinate&, const double& radius=ROBOT_RADIUS, const std::string& laserConfigFile=LASER_CONFIG_FILE);
    Robot(double, double, double); //TODO

    std::vector<double> getDistances() const; //TODO Abstände von LaserSensoren zurückgeben
};

#endif // ROBOT_H
