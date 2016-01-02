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
	Object(World* const world, const CoordinateSystem& base);
	virtual ~Object();
	virtual double evalLaser(const Laser& laser) const = 0;

	const CoordinateSystem& getBase() const;
};

#endif // OBJECT_H
