#include "lasersensor.h"

#include "laser.h"

LaserSensor::LaserSensor(const CoordinateSystem &base):Object(base)
{

}

double LaserSensor::evalLaser(const Laser &) const
{
	return Laser::range;
}
