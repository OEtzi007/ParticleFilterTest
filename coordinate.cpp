#include "coordinate.h"

#include "vector.h"

Coordinate::Coordinate(double x, double y):x(x),y(y)
{

}

Vector operator-(const Coordinate& a, const Coordinate& b){
	return Vector(a.x-b.x,a.y-b.y);
}
