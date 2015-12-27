#ifndef SPHERE_H
#define SPHERE_H

#include "mapobject.h"
#include "coordinate.h"

class Sphere : public MapObject
{
private:
	Coordinate origin;
	double radius;
public:
	Sphere(const Coordinate&, const double&);

	double evalLaser(const Laser&) const;
};

#endif // SPHERE_H
