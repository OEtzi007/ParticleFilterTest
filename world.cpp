#include "world.h"

World::World() : base(CoordinateSystem(0,Coordinate(0))), width(0), height(0) //TODO
{

}

void World::reset(Interfaces& interfaces)
{
	ifs=&interfaces;
}

void World::tick()
{
	//TODO
}
