#ifndef WORLD_H
#define WORLD_H

#include "coordinatesystem.h"

#include "interface.h"

class World
{
private:
	Interfaces* ifs;
public:
	const CoordinateSystem base;
	const double width;
	const double height;

	World();

	void reset(Interfaces&);
	void tick();
};

#endif // WORLD_H
