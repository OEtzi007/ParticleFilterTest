#ifndef SIMULATION_H
#define SIMULATION_H

#include <QtCore>

class Simulation : public QThread
{
public:
    Simulation();

    void run();
};

#endif // SIMULATION_H
