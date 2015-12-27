#include "vector.h"

Vector::Vector(double x, double y):Coordinate(x,y)
{

}

Vector operator*(const double& s, const Vector& vec){
	return Vector(s*vec.x,s*vec.y);
}

Vector operator*(const Vector& vec, const double& s){
	return s*vec;
}

double operator*(const Vector& u, const Vector& v){
	return u.x*v.x+u.y*v.y;
}
