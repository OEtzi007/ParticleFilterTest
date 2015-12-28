#include "vector.h"

#include <cmath>

Vector::Vector(const double &x, const double &y):Coordinate(x,y)
{

}

double Vector::length() const
{
	return sqrt((*this)*(*this));
}

Vector operator*(const double& s, const Vector& vec){
	return Vector(s*vec.x,s*vec.y);
}

Vector operator*(const Vector& vec, const double& s){
	return s*vec;
}

Vector operator/(const Vector& vec, const double& s)
{
	return Vector(vec.x/s,vec.y/s);
}

double operator*(const Vector& u, const Vector& v){
	return u.x*v.x+u.y*v.y;
}
