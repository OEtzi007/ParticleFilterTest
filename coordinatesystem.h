#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "coordinate.h"

#include "vector.h"

class CoordinateSystem : public Coordinate
{
public:
	Vector axis[3];

	CoordinateSystem(const CoordinateSystem* const, Coordinate, Vector, Vector);
	CoordinateSystem(const CoordinateSystem* const, Coordinate, Vector);
	CoordinateSystem(const CoordinateSystem* const, Coordinate);

	Coordinate& transform(const CoordinateSystem* const)=delete; //TODO and add different transform for vector and cooSystem

	CoordinateSystem& moveAxes(Vector,Vector);
	CoordinateSystem& moveAxes(Vector);
	CoordinateSystem& moveAxes();
};

#endif // COORDINATESYSTEM_H
