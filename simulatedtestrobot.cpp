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
	return distances;
}

/*double LaserSensor::getNonErrorMeasurement() const //TODO remove
{
	//use sphere coordinates
	Vector direction(&this->base,1,0,0);
	Laser laser(&this->base,this->base,direction,range);
	double exactMeasure=world->evalLaser(laser);
	return result;
}*/

void SimulatedTestRobot::set(const double& x, const double& y, const double& phi) {
	this->base.x=x;
	this->base.y=y;
	this->base.moveAxes(Vector(this->base.getBase(), std::cos(phi), std::sin(phi)));
}
