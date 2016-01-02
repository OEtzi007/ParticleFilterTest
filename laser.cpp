#include "laser.h"

Laser::Laser(const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& direction, const double& range):
	CoordinateSystem(refBase, origin, direction),
	range(range)
{
}

double Laser::getRange() const
{
	return range;
}
