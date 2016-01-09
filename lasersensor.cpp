#include "lasersensor.h"

#include <random>
#include "constants.h"
#include "laser.h"
#include "world.h"

const double LaserSensor::range=LASER_RANGE;
const double LaserSensor::relSigmaL=LASER_REL_SIGMA_L;
const double LaserSensor::sigmaTheta=LASER_SIGMA_THETA;
const double LaserSensor::errorProbability=LASER_ERROR_PROBABILITY;
const double LaserSensor::measurementFrequence=LASER_MEASUREMENT_FREQUENCE;

LaserSensor::LaserSensor(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& direction):
	Object(world,
		   CoordinateSystem(refBase,
							origin,
							direction))
{
	//FIXME lastTimeMeasurement and lastMeasurement needed to be set correctly and also must be able to reset if simulation gets resetted
}

double LaserSensor::getMeasurement()
{
	double curTime=world->getTime();
	if(curTime-lastTimeMeasurement<1./measurementFrequence)
		return lastMeasurement;
	else
		lastTimeMeasurement=curTime;
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
	lastMeasurement=std::normal_distribution<double>(exactMeasure,exactMeasure*relSigmaL)(RANDOM_ENGINE);
	if(lastMeasurement<0){
		lastMeasurement=0;
		return lastMeasurement;
	}
	return lastMeasurement;
}

double LaserSensor::getNonErrorMeasurement() const //TODO remove later
{
	Vector direction(&this->base,1,0,0);
	Laser laser(&this->base,this->base,direction,range);
	double exactMeasure=world->evalLaser(laser);
	return exactMeasure;
}

double LaserSensor::evalLaser(const Laser & laser) const
{
	return laser.getRange();
}
