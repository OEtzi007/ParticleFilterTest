#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "coordinate.h"

#include "vector.h"

class CoordinateSystem : public Coordinate
{
private:
	CoordinateSystem* const base;
	Vector axis[3];
public:
	CoordinateSystem(CoordinateSystem* const, const Coordinate&, const Vector&, const Vector&);
	CoordinateSystem(CoordinateSystem* const, const Coordinate&, const Vector&);
};

#endif // COORDINATESYSTEM_H
