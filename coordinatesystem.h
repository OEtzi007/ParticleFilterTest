#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "coordinate.h"

#include "vector.h"

class CoordinateSystem : public Coordinate
{
private:
	Vector axis[3];
public:
	CoordinateSystem(const CoordinateSystem* const, Coordinate, const Vector&, const Vector&);
	CoordinateSystem(const CoordinateSystem* const, const Coordinate&, const Vector&);
	CoordinateSystem(const CoordinateSystem* const, const Coordinate&);
};

#endif // COORDINATESYSTEM_H
