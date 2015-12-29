#include "sphere.h"

#include <cmath>
#include "laser.h"

Sphere::Sphere(CoordinateSystem * const base, const Coordinate& origin, const double& radius):Object(CoordinateSystem(base,origin)),radius(radius)
{

}

double Sphere::evalLaser(const Laser& laser) const{
	Vector toOrigin=base-laser.getOrigin();
	double k=(toOrigin*laser.getDirection());
	double dist=(toOrigin-k*laser.getDirection()).length();
	if(dist>radius)
		return Laser::range;
	double delta=sqrt(radius*radius-dist*dist);
	double solutionOne=k-delta;
	if(solutionOne>=0 && solutionOne<=Laser::range)
		return solutionOne;
	double solutionTwo=k+delta;
	if(solutionTwo>=0 && solutionTwo<=Laser::range)
		return solutionTwo;
	return Laser::range;
}
