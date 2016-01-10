#ifndef SIMULATION_H
#define SIMULATION_H

#include "thread.h"

#include "world.h"
#include "robotintelligence.h"

class DataPublisher;

class Simulation : public Thread
{
private:
	DataPublisher* subscriber;

	Interfaces ifs;
	World world;
	RobotIntelligence ai;

	unsigned long long int ticks;
public:
	Simulation(DataPublisher* const subscriber);

	void run();

	void initProcess();
};

#endif // SIMULATION_H
