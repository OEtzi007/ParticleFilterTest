#ifndef VECTOR_H
#define VECTOR_H

#include "coordinate.h"

class Vector : public Coordinate
{
public:
	Vector(double, double);

	friend Vector operator*(const double&, const Vector&);
	friend Vector operator*(const Vector&, const double&);
	friend double operator*(const Vector&, const Vector&);
};

Vector operator*(const double&, const Vector&);
Vector operator*(const Vector&, const double&);
double operator*(const Vector&, const Vector&);

#endif // VECTOR_H
