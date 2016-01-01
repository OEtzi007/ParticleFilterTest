#include "laser.h"

Laser::Laser(const CoordinateSystem* const base, const Coordinate& origin, const Vector& xAxis, const double& range) : CoordinateSystem(base, origin, xAxis) , range(range)
{
}

double Laser::getRange() const
{
	return range;
}
