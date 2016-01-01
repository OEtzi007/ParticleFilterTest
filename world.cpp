#include "world.h"
#include "constants.h"

World::World() : base(CoordinateSystem(0,Coordinate(0))), width(0), height(0), robot(&base, Coordinate(0)) //TODO
{

}

void World::reset(Interfaces& interfaces)
{
	ifs=&interfaces;
}

void World::tick()
{
	//TODO
	robot.move(ifs->motorActuatorI);
	robot.updateSensors(ifs->laserSensorI);
	updateTime();
}

void World::updateTime() {
	ifs->timeI.setData({ifs->timeI.getData("time") + TIME_PER_TICK});
}
