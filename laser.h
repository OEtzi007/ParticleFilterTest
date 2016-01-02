#ifndef LASER_H
#define LASER_H

#include "coordinatesystem.h"

class Laser : public CoordinateSystem
{
private:
	double range;
public:
	Laser(const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& direction, const double& range);

	double getRange() const;
};

#endif // LASER_H
