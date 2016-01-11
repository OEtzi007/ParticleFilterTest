#ifndef SIMULATION_H
#define SIMULATION_H

#include "world.h"
#include "robotintelligence.h"

class Simulation
{
private:
	Interfaces ifs;
	World world;
	RobotIntelligence ai;

	unsigned long long int ticks;
public:
	Simulation();

	void run();

	void initProcess();
};

#endif // SIMULATION_H
