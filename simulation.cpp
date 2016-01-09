#include "simulation.h"

#include <thread>

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

	std::thread aiThread{ai};

	while(ticks<TOTAL_TICKS)	//TODO add a finish line
	{
		world.tick();
#ifdef DEBUG
		/*
		std::cout << "simulation laser data:" << std::endl;	//NOTE io section
		std::vector<double> curData = ifs.laserSensorI.getAllData();
		for(unsigned int i=0; i<curData.size(); ++i)
			std::cout << curData[i] << std::endl;
		std::cout << std::endl;
		*/
#endif
		++ticks;
		emit itTicked(ticks);
	}

	ai.shutDown();
	aiThread.join();
}

void Simulation::initProcess()
{
	ticks=0;
	ifs.timeI.setData("time",0);
	ifs.motorActuatorI.setAllData(std::vector<double>(3,0));
	ifs.laserSensorI.setAllData(std::vector<double>(12,1));
	world.reset(ifs);
	ai.reset(ifs);
}
