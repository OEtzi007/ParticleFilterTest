#include "vector.h"

#include <cmath>

Vector::Vector(const double &x, const double &y, const double &z):Coordinate(x,y,z)
{

}

Vector::Vector(const double &x, const double &y):Coordinate(x,y,0)
{

}

Vector::Vector()
{

}

double Vector::length() const
{
	return sqrt((*this)*(*this));
}

Coordinate operator+(const Coordinate& coo, const Vector& vec){
	return Coordinate(coo.x+vec.x,coo.y+vec.y,coo.z+vec.z);
}

Coordinate operator+(const Vector& vec, const Coordinate& coo){
	return Coordinate(coo.x+vec.x,coo.y+vec.y,coo.z+vec.z);
}

Vector operator*(const double& s, const Vector& vec){
	return Vector(s*vec.x,s*vec.y,s*vec.z);
}

Vector operator*(const Vector& vec, const double& s){
	return Vector(s*vec.x,s*vec.y,s*vec.z);
}

Vector operator/(const Vector& vec, const double& s)
{
	return Vector(vec.x/s,vec.y/s,vec.z/s);
}

double operator*(const Vector& u, const Vector& v){
	return u.x*v.x+u.y*v.y+u.z*v.z;
}

Vector cross(const Vector& a, const Vector& b){
	return Vector(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
