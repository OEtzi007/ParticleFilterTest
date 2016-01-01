#include "sphere.h"

#include <cmath>
#include "lasersensor.h"
#include "laser.h"

Sphere::Sphere(const CoordinateSystem * const base, const Coordinate& origin, const double& radius):Object(CoordinateSystem(base,origin)),radius(radius)
{

}

/* TODO remove
double Sphere::evalLaser(const Laser& laser) const
{
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
*/

double Sphere::evalLaser(const Laser& laser) const
{
	Coordinate origin_c(base);
	origin_c.transform(&laser);
	double dist=sqrt(origin_c.y*origin_c.y+origin_c.z*origin_c.z);
	if(dist>radius)
		return laser.getRange();
	double delta=sqrt(radius*radius-dist*dist);
	double solutionOne=origin_c.x-delta;
	if(solutionOne>=0 && solutionOne<=laser.getRange())
		return solutionOne;
	double solutionTwo=origin_c.x+delta;
	if(solutionTwo>=0 && solutionTwo<=laser.getRange())
		return solutionTwo;
	return laser.getRange();
}
