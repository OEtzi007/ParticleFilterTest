#include "simulation.h"

Simulation::Simulation():
	ifs{Interface(12,std::vector<std::string>(12,"laserSensor")),
		Interface(3,{"vx","vy","omega"}),
		Interface(1,{"time"})},
	world(&ifs),
	ai(ifs),
	ticks(0)	//TODO replace number 12 by laserConfig .lcfg
{
}

void Simulation::run()
{
	initProcess();

	//ai.start();
	//ai.wait();
	while(ticks<100000)	//TODO add a finish line
	{
		world.tick();
		++ticks;
	}

	//ai.quit();
}

void Simulation::initProcess()
{
	ticks=0;
	world.reset(ifs);
	ai.reset(ifs);
}
