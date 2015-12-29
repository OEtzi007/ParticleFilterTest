#include "coordinate.h"

#include "vector.h"

Coordinate::Coordinate(CoordinateSystem* const base, const double &x, const double &y, const double &z):base(base),x(x),y(y),z(z)
{
}
/*TODO remove
Coordinate& Coordinate::operator=(const Coordinate& coo)
{
	if(coo.base==this->base){
		this->x=coo.x;
		this->y=coo.y;
		this->z=coo.z;
	return *this;
}
*/

CoordinateSystem* Coordinate::getBase() const
{
	return base;
}

double Coordinate::getX() const
{
	return x;
}

double Coordinate::getY() const
{
	return y;
}

double Coordinate::getZ() const
{
	return z;
}

Vector operator-(Coordinate a, const Coordinate& b){
	a.transform(b.base);
	return Vector(b.base,a.x-b.x,a.y-b.y,a.z-b.z);
}
