#ifndef SIMULATION_H
#define SIMULATION_H

#include <QThread>

#include "world.h"
#include "robotintelligence.h"

class Simulation : public QThread
{
	Q_OBJECT
private:
	Interfaces ifs;
	World world;
	RobotIntelligence ai;

	unsigned long long int ticks;
public:
	Simulation();

	void run() Q_DECL_OVERRIDE ;

	void initProcess();

signals:
	void itTicked(int tick);
};

#endif // SIMULATION_H
