#include "simulatedtestrobot.h"

#include <cmath>
#include "map.h"

SimulatedTestRobot::SimulatedTestRobot(World* const world, const CoordinateSystem* const base, const Coordinate & origin, const double &radius, const std::string &laserConfigFile):Robot(world, base, origin, radius, laserConfigFile)
{
}

std::vector<double> SimulatedTestRobot::getNonErrorDistances() const{
	return std::vector<double>();	//TODO
}

void SimulatedTestRobot::set(double x, double y, double ori) {
	this->base.x=x;
	this->base.y=y;
	this->base.moveAxes(Vector(this->base.getBase(), std::cos(ori), std::sin(ori)));
}
