#include "simulation.h"

#ifdef DEBUG
#include <iostream>	//NOTE io
#endif

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

	ai.start();

	while(ticks<100000)	//TODO add a finish line
	{
		world.tick();
#ifdef DEBUG
		/*std::cout << "simulation laser data:" << std::endl;	//NOTE io section
		std::vector<double> curData = ifs.laserSensorI.getAllData();
		for(unsigned int i=0; i<curData.size(); ++i)
			std::cout << curData[i] << std::endl;
		std::cout << std::endl;*/
#endif
		++ticks;
	}

	ai.quit();
}

void Simulation::initProcess()
{
	ticks=0;
	world.reset(ifs);
	ai.reset(ifs);
}
