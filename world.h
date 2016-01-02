#ifndef WORLD_H
#define WORLD_H

#include "coordinatesystem.h"

#include "interface.h"
#include "robot.h"

class World
{
private:
	Interfaces* ifs;
	double time;
	std::vector<Object*> objects;
public:
	const double timePerTick;

	const CoordinateSystem base;
	const double width;
	const double height;
private:
	Robot robot;	//TODO include to object list
public:
	World(Interfaces* const interfaces);

	void reset(Interfaces& interfaces);
	void tick();
	void updateTime();

	double evalLaser(const Laser& laser) const;
};

#endif // WORLD_H
