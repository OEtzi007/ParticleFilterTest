#include "vector.h"

#include <cmath>

Vector::Vector(const CoordinateSystem* const base, const double &x, const double &y, const double &z):Coordinate(base,x,y,z)
{
}

double Vector::length() const
{
	return sqrt((*this)*(*this));
}

Coordinate operator+(const Coordinate& coo, Vector vec){
	vec.transform(coo.base);
	return Coordinate(coo.getBase(),coo.x+vec.x,coo.y+vec.y,coo.z+vec.z);
}

Coordinate operator+(Vector vec, const Coordinate& coo){
	vec.transform(coo.base);
	return Coordinate(coo.getBase(),coo.x+vec.x,coo.y+vec.y,coo.z+vec.z);
}

Vector operator*(const double& s, const Vector& vec){
	return Vector(vec.getBase(),s*vec.x,s*vec.y,s*vec.z);
}

Vector operator*(const Vector& vec, const double& s){
	return Vector(vec.getBase(),s*vec.x,s*vec.y,s*vec.z);
}

Vector operator/(const Vector& vec, const double& s)
{
	return Vector(vec.getBase(),vec.x/s,vec.y/s,vec.z/s);
}

double operator*(const Vector& u, Vector v){
	v.transform(u.getBase());
	return u.x*v.x+u.y*v.y+u.z*v.z;
}

Vector cross(const Vector& a, Vector b){
	b.transform(a.getBase());
	return Vector(a.getBase(),a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
