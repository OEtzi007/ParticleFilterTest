#include "world.h"

#include "constants.h"
#include "laser.h"

World::World() : time(0), timePerTick(TIME_PER_TICK), base(CoordinateSystem(0,Coordinate(0))), width(0), height(0), robot(this,&base, Coordinate(0)) //TODO
{
}

void World::reset(Interfaces& interfaces)
{
	time=0;
	ifs=&interfaces;
}

void World::tick()
{
	//TODO
	time*=timePerTick;
	robot.move(ifs->motorActuatorI);
	robot.updateSensors(ifs->laserSensorI);
	updateTime();
}

void World::updateTime() {
	ifs->timeI.setData({time});
}

double World::evalLaser(const Laser& laser) const
{
	double minMeasurement=laser.getRange();
	for(unsigned int i=0;i<objects.size();++i){
		double curMeasurement=objects[i]->evalLaser(laser);
		if(minMeasurement>curMeasurement)
			minMeasurement=curMeasurement;
	}
	return minMeasurement;
}
