#include "world.h"

#include "constants.h"
#include "laser.h"
#include "wall.h"

World::World(Interfaces* const interfaces):
	ifs(interfaces),
	time(0),
	objects(),
	timePerTick(TIME_PER_TICK),
	base(CoordinateSystem(CoordinateSystem::root,
						  Coordinate(CoordinateSystem::root))),
	width(MAP_WIDTH),
	height(MAP_HEIGHT),
	robot(this,
		  &base,
		  Coordinate(0)) //TODO place the robot according to config file
{
	objects.push_back(new Wall(this,&base,Coordinate(&base,MAP_X_MIN,MAP_Y_MIN),Vector(&base,1)));
	objects.push_back(new Wall(this,&base,Coordinate(&base,MAP_X_MIN,MAP_Y_MIN),Vector(&base,0,1)));
	objects.push_back(new Wall(this,&base,Coordinate(&base,MAP_X_MIN+width,MAP_Y_MIN),Vector(&base,-1)));
	objects.push_back(new Wall(this,&base,Coordinate(&base,MAP_X_MIN,MAP_Y_MIN+height),Vector(&base,0,-1)));
}

void World::reset(Interfaces& interfaces)
{
	time=0;
	ifs=&interfaces;
	robot.updateSensors(ifs->laserSensorI);
}

#ifdef DEBUG
#include <iostream>
#endif
void World::tick()
{
	time+=timePerTick;
	robot.move(ifs->motorActuatorI);
	robot.updateSensors(ifs->laserSensorI);
	updateTime();
#ifdef DEBUG
	std::cout << "World knows at time " << time << ":\tx=" << robot.getBase().x << "\ty=" << robot.getBase().y << "\tori=" << atan2(robot.getBase().axes[0].y, robot.getBase().axes[0].x) << std::endl;
#endif
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
