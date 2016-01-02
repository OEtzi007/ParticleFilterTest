#include "simulatedtestrobot.h"

#include <cmath>
#include "map.h"

SimulatedTestRobot::SimulatedTestRobot(World* const world, const CoordinateSystem* const refBase, const Coordinate & origin, const double &radius, const std::string &laserConfigFile):
	Robot(world,
		  refBase,
		  origin,
		  radius,
		  laserConfigFile)
{
}

std::vector<double> SimulatedTestRobot::getNonErrorDistances() const{
	return std::vector<double>();	//FIXME kakuro
}

void SimulatedTestRobot::set(const double& x, const double& y, const double& phi) {
	this->base.x=x;
	this->base.y=y;
	this->base.moveAxes(Vector(this->base.getBase(), std::cos(phi), std::sin(phi)));
}
