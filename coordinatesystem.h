#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "coordinate.h"

#include "vector.h"

class CoordinateSystem : public Coordinate
{
private:
	static bool rootExists;
public:
	static const CoordinateSystem* const root;

	Vector axes[3];

	CoordinateSystem(const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& xAxis, const Vector& yAxis);
	CoordinateSystem(const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& xAxis);
	CoordinateSystem(const CoordinateSystem* const refBase, const Coordinate& origin);
	~CoordinateSystem();

	CoordinateSystem transform(const CoordinateSystem* const toSystem) const;

	CoordinateSystem& moveAxes(const Vector& xAxis, const Vector& yAxis);
	CoordinateSystem& moveAxes(const Vector& xAxis);
	CoordinateSystem& moveAxes();
};

#endif // COORDINATESYSTEM_H
