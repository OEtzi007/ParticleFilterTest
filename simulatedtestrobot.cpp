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
	std::vector<double> distances;
	for(unsigned int i=0;i<laserSensors.size();++i){
		distances.push_back(laserSensors[i].getNonErrorMeasurement());
	}
	return std::vector<double>(laserSensors.size(),1);
}

void SimulatedTestRobot::set(const double& x, const double& y, const double& phi) {
	this->base.x=x;
	this->base.y=y;
	this->base.z=0;
	this->base.moveAxes(Vector(this->base.getBase(), std::cos(phi), std::sin(phi)));
}
