#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "coordinate.h"

#include "vector.h"

class CoordinateSystem : public Coordinate
{
private:
	Vector axis[3];
public:
	CoordinateSystem(const CoordinateSystem* const, Coordinate, Vector, Vector);
	CoordinateSystem(const CoordinateSystem* const, Coordinate, Vector);
	CoordinateSystem(const CoordinateSystem* const, Coordinate);
};

#endif // COORDINATESYSTEM_H
