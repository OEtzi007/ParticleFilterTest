#ifndef OBJECT_H
#define OBJECT_H

#include "coordinatesystem.h"

class Laser;
class World;

class Object
{
protected:
	World* const world;
	CoordinateSystem base;
public:
	Object(World* const, const CoordinateSystem&);
	virtual ~Object();
	virtual double evalLaser(const Laser&) const = 0;
};

#endif // OBJECT_H
