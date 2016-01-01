#include "robot.h"

#include <fstream>
#include <cmath>
#include <random>

#include "vector.h"
#include "lasersensor.h"

Robot::Robot(const CoordinateSystem* const base, const Coordinate & origin, const double &radius, const std::string &laserConfigFile):Sphere(base,origin,radius)
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
		laserSensors.push_back(LaserSensor(&(this->base),laserOrigin,direction));
	}
}

void Robot::move(Interface motorData) {
	std::normal_distribution<double> v_x(motorData.getData("vx"), MotorActuatorInterface::relSigmaV*motorData.getData("vx"));
	std::normal_distribution<double> v_y(motorData.getData("vy"), MotorActuatorInterface::relSigmaV*motorData.getData("vy"));
	std::normal_distribution<double> omega(motorData.getData("omega"), MotorActuatorInterface::relSigmaOmega*motorData.getData("omega"));
	std::default_random_engine re;

}

void Robot::updateSensors(Interface laserData) {

}
