#include "lasersensor.h"

#include "laser.h"

LaserSensor::LaserSensor(const CoordinateSystem* const base, const Coordinate& origin, const Vector& direction):Object(CoordinateSystem(base,origin,direction))
{

}

double LaserSensor::evalLaser(const Laser &) const
{
	return Laser::range;
}
