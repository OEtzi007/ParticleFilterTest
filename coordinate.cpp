#include "coordinate.h"

#include "vector.h"

Coordinate::Coordinate(const CoordinateSystem* const base, const double &x, const double &y, const double &z):base(base),x(x),y(y),z(z)
{
}

const CoordinateSystem* Coordinate::getBase() const
{
	return base;
}

Vector operator-(Coordinate a, const Coordinate& b){
	a.transform(b.base);
	return Vector(b.base,a.x-b.x,a.y-b.y,a.z-b.z);
}
