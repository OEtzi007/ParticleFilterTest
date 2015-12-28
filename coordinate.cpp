#include "coordinate.h"

#include "vector.h"

Coordinate::Coordinate(const double &x, const double &y):x(x),y(y)
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

Vector operator-(const Coordinate& a, const Coordinate& b){
	return Vector(a.x-b.x,a.y-b.y);
}
