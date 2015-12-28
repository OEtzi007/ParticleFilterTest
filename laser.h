#ifndef LASER_H
#define LASER_H

#include "coordinate.h"
#include "vector.h"

class Laser
{
private:
	Coordinate origin;
	Vector direction;	//normed to length 1
public:
	static const double range;

	Laser(const Coordinate& origin, const Vector& direction);

	Coordinate getOrigin() const;
	Vector getDirection() const;
};

#endif // LASER_H
