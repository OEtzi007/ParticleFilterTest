#ifndef VECTOR_H
#define VECTOR_H

#include "coordinate.h"

class Vector : public Coordinate
{
public:
	Vector(const CoordinateSystem* const, const double& x=0, const double& y=0, const double& z=0);

	Vector transform(const CoordinateSystem* const) const;

	double length() const;

	friend Vector operator+(const Vector&, const Vector&);
	friend Coordinate operator+(const Coordinate&, const Vector&);
	friend Coordinate operator+(const Vector&, const Coordinate&);
	friend Vector operator*(const double&, const Vector&);
	friend Vector operator*(const Vector&, const double&);
	friend Vector operator/(const Vector&, const double&);
	friend double operator*(const Vector&, const Vector&);
	friend Vector cross(const Vector&, const Vector&);
};

#endif // VECTOR_H
