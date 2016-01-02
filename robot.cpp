#include "robot.h"

#include <fstream>
#include <cmath>
#include <random>

#include "vector.h"
#include "lasersensor.h"
#include "motoractuator.h"

Robot::Robot(World* const world, const CoordinateSystem* const refBase, const Coordinate & origin, const double &radius, const std::string &laserConfigFile):
	Sphere(world,
		   refBase,
		   origin,
		   radius)
{
	std::ifstream lcfg(laserConfigFile);
	int n;
	lcfg >> n;
	for(int i=0;i<n;i++){
		double phi;
		lcfg >> phi;
		phi*=2*PI/360.;
		Vector direction(&(this->base),cos(phi),sin(phi));
		Coordinate laserOrigin=direction*radius;
		laserSensors.push_back(LaserSensor(world,&(this->base),laserOrigin,direction));
	}
}

void Robot::move(Interface& actuatorInterface) {
	std::normal_distribution<double> v_x(actuatorInterface.getData("vx"), MotorActuator::relSigmaV*actuatorInterface.getData("vx"));
	std::normal_distribution<double> v_y(actuatorInterface.getData("vy"), MotorActuator::relSigmaV*actuatorInterface.getData("vy"));
	std::normal_distribution<double> omega(actuatorInterface.getData("omega"), MotorActuator::relSigmaOmega*actuatorInterface.getData("omega"));

	double s_x = v_x(RANDOM_ENGINE)*TIME_PER_TICK;
	double s_y = v_y(RANDOM_ENGINE)*TIME_PER_TICK;
	double delOri=omega(RANDOM_ENGINE)*TIME_PER_TICK;

	this->base.x+=s_x;
	this->base.y+=s_y;
	this->base.moveAxes(Vector(&this->base, std::cos(delOri), std::sin(delOri)));
}

void Robot::updateSensors(Interface& sensorInterface) const{
	std::vector<double> measurements;
	for(unsigned int i=0;i<laserSensors.size();++i){
		measurements.push_back(laserSensors[i].getMeasurement());
	}
	sensorInterface.setData(measurements);
}
