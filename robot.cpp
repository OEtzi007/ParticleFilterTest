#include "robot.h"

#include <fstream>
#include <cmath>
#include <random>

#include "vector.h"
#include "lasersensor.h"
#include "motoractuator.h"

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
	std::normal_distribution<double> v_x(motorData.getData("vx"), MotorActuator::relSigmaV*motorData.getData("vx"));
	std::normal_distribution<double> v_y(motorData.getData("vy"), MotorActuator::relSigmaV*motorData.getData("vy"));
	std::normal_distribution<double> omega(motorData.getData("omega"), MotorActuator::relSigmaOmega*motorData.getData("omega"));
	std::default_random_engine RANDOM_ENGINE;

	double s_x = v_x(RANDOM_ENGINE)*TIME_PER_TICK;
	double s_y = v_y(RANDOM_ENGINE)*TIME_PER_TICK;
	double delOri=omega(RANDOM_ENGINE)*TIME_PER_TICK;

	this->base.x+=s_x;
	this->base.y+=s_y;
	this->base.moveAxes(Vector(&this->base, std::cos(delOri), std::sin(delOri)));
}

void Robot::updateSensors(Interface laserData) {

}
