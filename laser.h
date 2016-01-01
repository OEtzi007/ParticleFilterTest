#ifndef LASER_H
#define LASER_H

#include "coordinatesystem.h"

class Laser : public CoordinateSystem
{
private:
	double range;
public:
	Laser(const CoordinateSystem* const, const Coordinate&, const Vector&, const double&);

	double getRange() const;
};

#endif // LASER_H
