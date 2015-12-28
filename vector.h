#ifndef VECTOR_H
#define VECTOR_H

#include "coordinate.h"

class Vector : public Coordinate
{
public:
	Vector(const double&, const double&);

	double length() const;

	friend Vector operator*(const double&, const Vector&);
	friend Vector operator*(const Vector&, const double&);
	friend Vector operator/(const Vector&, const double&);
	friend double operator*(const Vector&, const Vector&);
};

#endif // VECTOR_H
