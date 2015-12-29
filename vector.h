#ifndef VECTOR_H
#define VECTOR_H

#include "coordinate.h"

class Vector : public Coordinate
{
public:
	Vector(const CoordinateSystem* const, const double& x=0, const double& y=0, const double& z=0);

	double length() const;

	friend Coordinate operator+(const Coordinate&, Vector);
	friend Coordinate operator+(Vector, const Coordinate&);
	friend Vector operator*(const double&, const Vector&);
	friend Vector operator*(const Vector&, const double&);
	friend Vector operator/(const Vector&, const double&);
	friend double operator*(const Vector&, Vector);
	friend Vector cross(const Vector&, Vector);
};

#endif // VECTOR_H
