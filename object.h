#ifndef OBJECT_H
#define OBJECT_H

#include "coordinatesystem.h"

class Laser;

class Object
{
protected:
	CoordinateSystem base;
public:
	Object(const CoordinateSystem&);
	virtual ~Object();
	virtual double evalLaser(const Laser&) const = 0;
};

#endif // OBJECT_H
