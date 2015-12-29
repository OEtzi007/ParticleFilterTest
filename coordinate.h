#ifndef COORDINATE_H
#define COORDINATE_H

class Vector;

class Coordinate
{
protected:
	double x;
	double y;
	double z;
public:
	Coordinate(const double&, const double&, const double&);
	Coordinate(const double&, const double&);
	Coordinate();

	double getX() const;
	double getY() const;
	double getZ() const;

	friend Vector operator-(const Coordinate&, const Coordinate&);
	friend Coordinate operator+(const Coordinate&, const Vector&);
	friend Coordinate operator+(const Vector&, const Coordinate&);
};

#endif // COORDINATE_H
