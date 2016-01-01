#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "coordinate.h"

#include "vector.h"

class CoordinateSystem : public Coordinate
{
public:
	Vector axes[3];

	CoordinateSystem(const CoordinateSystem* const, Coordinate, Vector, Vector);
	CoordinateSystem(const CoordinateSystem* const, Coordinate, Vector);
	CoordinateSystem(const CoordinateSystem* const, Coordinate);

	CoordinateSystem transform(const CoordinateSystem* const) const;

	CoordinateSystem& moveAxes(Vector,Vector);
	CoordinateSystem& moveAxes(Vector);
	CoordinateSystem& moveAxes();
};

#endif // COORDINATESYSTEM_H
