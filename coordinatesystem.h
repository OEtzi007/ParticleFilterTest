#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "coordinate.h"

#include "vector.h"

class CoordinateSystem : public Coordinate
{
public:
	Vector axes[3];

	CoordinateSystem(const CoordinateSystem* const, const Coordinate&, const Vector&, const Vector&);
	CoordinateSystem(const CoordinateSystem* const, const Coordinate&, const Vector&);
	CoordinateSystem(const CoordinateSystem* const, const Coordinate&);

	CoordinateSystem transform(const CoordinateSystem* const) const;

	CoordinateSystem& moveAxes(const Vector&, const Vector&);
	CoordinateSystem& moveAxes(const Vector&);
	CoordinateSystem& moveAxes();
};

#endif // COORDINATESYSTEM_H
