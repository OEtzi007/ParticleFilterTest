#ifndef LASER_H
#define LASER_H

#include "coordinatesystem.h"

class Laser : public CoordinateSystem
{
public:
	static const double range;
	static const double relSigmaL;

	Laser(const CoordinateSystem* const, Coordinate, Vector, Vector);
	Laser(const CoordinateSystem* const, Coordinate, Vector);
	Laser(const CoordinateSystem* const, Coordinate);
};

#endif // LASER_H
