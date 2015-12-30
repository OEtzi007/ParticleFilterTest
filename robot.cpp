#include "robot.h"

#include <fstream>
#include <cmath>

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
