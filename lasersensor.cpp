#include "lasersensor.h"

#include "constants.h"
#include "laser.h"

//const double LaserSensor::range=LASER_RANGE;
const double LaserSensor::relSigmaL=REL_SIGMA_L;

LaserSensor::LaserSensor(const CoordinateSystem* const base, const Coordinate& origin, const Vector& direction):Object(CoordinateSystem(base,origin,direction))
{

}

double LaserSensor::evalLaser(const Laser & laser) const
{
	return laser.getRange();
}
