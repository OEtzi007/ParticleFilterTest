#ifndef COORDINATE_H
#define COORDINATE_H

class CoordinateSystem;
class Vector;

class Coordinate
{
protected:
	const CoordinateSystem* refBase;
public:
	double x;
	double y;
	double z;

	Coordinate(const CoordinateSystem* const refBase, const double& x=0, const double& y=0, const double& z=0);

	Coordinate transform(const CoordinateSystem* const toSystem) const;

	const CoordinateSystem* getBase() const;

	friend Vector operator-(const Coordinate&, const Coordinate&);
	friend Coordinate operator+(const Coordinate&, const Vector&);
	friend Coordinate operator+(const Vector&, const Coordinate&);
};

#endif // COORDINATE_H
