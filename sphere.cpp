#include "sphere.h"

#include <cmath>
#include "lasersensor.h"
#include "laser.h"

Sphere::Sphere(World* const world, const CoordinateSystem * const refBase, const Coordinate& origin, const double& radius):
	Object(world,
		   CoordinateSystem(refBase,
							origin)),
	radius(radius)
{
}

double Sphere::evalLaser(const Laser& laser) const
{
	Coordinate origin_c(base);
	origin_c=origin_c.transform(&laser);
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
