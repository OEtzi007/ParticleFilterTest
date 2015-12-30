#ifndef COORDINATE_H
#define COORDINATE_H

class CoordinateSystem;
class Vector;

class Coordinate
{
protected:
	const CoordinateSystem* base;
public:
	double x;
	double y;
	double z;

	Coordinate(const CoordinateSystem* const, const double& x=0, const double& y=0, const double& z=0);

	Coordinate& transform(const CoordinateSystem* const);

	const CoordinateSystem* getBase() const;

	friend Vector operator-(Coordinate, const Coordinate&);
	friend Coordinate operator+(const Coordinate&, Vector);
	friend Coordinate operator+(Vector, const Coordinate&);
};

#endif // COORDINATE_H
