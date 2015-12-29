#include "coordinate.h"

#include "vector.h"

Coordinate::Coordinate(const double &x, const double &y, const double &z):x(x),y(y),z(z)
{

}

Coordinate::Coordinate(const double &x, const double &y):x(x),y(y),z(0)
{

}

Coordinate::Coordinate():x(0),y(0),z(0)
{

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

Vector operator-(const Coordinate& a, const Coordinate& b){
	return Vector(a.x-b.x,a.y-b.y,a.z-b.z);
}
