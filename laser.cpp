#include "laser.h"

const double Laser::range=5;

Laser::Laser(const Coordinate& origin, const Vector& direction):origin(origin),direction(direction/direction.length())
{

}

Coordinate Laser::getOrigin() const{
	return origin;
}

Vector Laser::getDirection() const{
	return direction;
}
