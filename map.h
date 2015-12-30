#ifndef MAP_H
#define MAP_H

#include "world.h"

#include "coordinate.h"

class Map : public World
{
public:
	static const Coordinate origin;
	static const double width;
	static const double height;

    static const CoordinateSystem* const base;

	Map();
};

#endif // MAP_H
