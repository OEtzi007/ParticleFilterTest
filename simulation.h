#ifndef SIMULATION_H
#define SIMULATION_H

#include "world.h"
#include "robotintelligence.h"

class Simulation
{
	Q_OBJECT
private:
	Interfaces ifs;
	World world;
	RobotIntelligence ai;

	unsigned long long int ticks;
public:
	Simulation();

	void run();

	void initProcess();

signals:
	void itTicked(int tick);
};

#endif // SIMULATION_H
