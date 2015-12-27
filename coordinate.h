#ifndef COORDINATE_H
#define COORDINATE_H

class Vector;

class Coordinate
{
protected:
	double x;
	double y;
public:
	Coordinate(double, double);

friend Vector operator-(const Coordinate&, const Coordinate&);
};

#endif // COORDINATE_H
