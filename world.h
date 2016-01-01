#ifndef WORLD_H
#define WORLD_H

#include "coordinatesystem.h"

class World
{
public:
	const CoordinateSystem base;
	const double width;
	const double height;

	World();
};

#endif // WORLD_H
