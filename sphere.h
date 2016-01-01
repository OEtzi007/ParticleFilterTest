#ifndef SPHERE_H
#define SPHERE_H

#include "object.h"
#include "coordinate.h"

class Sphere : public Object
{
	double radius;
public:
	Sphere(World* const, const CoordinateSystem* const, const Coordinate&, const double&);

	double evalLaser(const Laser&) const;
};

#endif // SPHERE_H
