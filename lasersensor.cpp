#include "lasersensor.h"

#include <random>
#include "constants.h"
#include "laser.h"
#include "world.h"

const double LaserSensor::range=LASER_RANGE;
const double LaserSensor::relSigmaL=LASER_REL_SIGMA_L;
const double LaserSensor::sigmaTheta=LASER_SIGMA_THETA;
const double LaserSensor::errorProbability=LASER_ERROR_PROBABILITY;

LaserSensor::LaserSensor(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& direction):
	Object(world,
		   CoordinateSystem(refBase,
							origin,
							direction))
{

}

double LaserSensor::getMeasurement() const
{
	//use sphere coordinates
	double theta=std::normal_distribution<double>(0,sigmaTheta)(RANDOM_ENGINE);
	theta=std::abs(theta);
	if(theta>PI)
		theta=PI;
	double phi=std::uniform_real_distribution<double>(0,2.*PI)(RANDOM_ENGINE);
	Vector direction(&this->base,cos(theta),cos(phi)*sin(theta),sin(phi)*sin(theta));
	Laser laser(&this->base,this->base,direction,range);
	double exactMeasure;
	if(std::uniform_real_distribution<double>(0,1)(RANDOM_ENGINE)<errorProbability)
		exactMeasure=laser.getRange();
	else
		exactMeasure=world->evalLaser(laser);
	double result=std::normal_distribution<double>(exactMeasure,exactMeasure*relSigmaL)(RANDOM_ENGINE);
	if(result<0)
		return 0;
	return result;
}

double LaserSensor::evalLaser(const Laser & laser) const
{
	return laser.getRange();
}
