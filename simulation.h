#ifndef SIMULATION_H
#define SIMULATION_H

#include <QThread>

#include "world.h"
#include "robotintelligence.h"

class Simulation : public QThread
{
private:
	World world;
	Interfaces ifs;
	RobotIntelligence ai;

	unsigned long long int ticks;
public:
	Simulation();

	void run() Q_DECL_OVERRIDE ;

	void initProcess();
};

#endif // SIMULATION_H
