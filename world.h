#ifndef WORLD_H
#define WORLD_H

#include "coordinatesystem.h"

#include "interface.h"
#include "robot.h"

class World
{
private:
	Interfaces* ifs;
public:
	const CoordinateSystem base;
	const double width;
	const double height;
private:
	Robot robot;
public:
	World();

	void reset(Interfaces&);
	void tick();
	void updateTime();
};

#endif // WORLD_H
