#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "coordinate.h"

class Sphere : public Object
{
	double radius;
public:
	Sphere(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin, const double& radius);

	double evalLaser(const Laser& laser) const;
};

#endif // SPHERE_H
