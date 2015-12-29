#ifndef COORDINATE_H
#define COORDINATE_H

class CoordinateSystem;
class Vector;

class Coordinate
{
private:
	CoordinateSystem* base;
protected:
	double x;
	double y;
	double z;
public:

	Coordinate(CoordinateSystem* const, const double& x=0, const double& y=0, const double& z=0);
	//Coordinate& operator=(const Coordinate&); TODO remove

	Coordinate& transform(const CoordinateSystem* const); //TODO and add different transform for vector

	CoordinateSystem* getBase() const;
	double getX() const;
	double getY() const;
	double getZ() const;

	friend Vector operator-(Coordinate, const Coordinate&);
	friend Coordinate operator+(const Coordinate&, Vector);
	friend Coordinate operator+(Vector, const Coordinate&);
};

#endif // COORDINATE_H
