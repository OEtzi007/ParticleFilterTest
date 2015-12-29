#include "lasersensor.h"

#include "laser.h"

LaserSensor::LaserSensor(CoordinateSystem* const base, const Coordinate& origin, const Vector& direction):Object(CoordinateSystem(base,origin,direction))
{

}

double LaserSensor::evalLaser(const Laser &) const
{
	return Laser::range;
}
