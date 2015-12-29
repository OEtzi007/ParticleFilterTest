#ifndef VECTOR_H
#define VECTOR_H

#include "coordinate.h"

class Vector : public Coordinate
{
public:
	Vector(const double&, const double&, const double&);
	Vector(const double&, const double&);
	Vector();

	double length() const;

	friend Coordinate operator+(const Coordinate&, const Vector&);
	friend Coordinate operator+(const Vector&, const Coordinate&);
	friend Vector operator*(const double&, const Vector&);
	friend Vector operator*(const Vector&, const double&);
	friend Vector operator/(const Vector&, const double&);
	friend double operator*(const Vector&, const Vector&);
};

#endif // VECTOR_H
