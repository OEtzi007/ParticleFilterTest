#ifndef COORDINATE_H
#define COORDINATE_H

class CoordinateSystem;
class Vector;

class Coordinate
{
private:
	const CoordinateSystem* base;
public:
	double x;
	double y;
	double z;

	Coordinate(const CoordinateSystem* const, const double& x=0, const double& y=0, const double& z=0);
	//Coordinate& operator=(const Coordinate&); TODO remove

	Coordinate& transform(const CoordinateSystem* const); //TODO and add different transform for vector

	const CoordinateSystem* getBase() const;

	friend Vector operator-(Coordinate, const Coordinate&);
	friend Coordinate operator+(const Coordinate&, Vector);
	friend Coordinate operator+(Vector, const Coordinate&);
};

#endif // COORDINATE_H
