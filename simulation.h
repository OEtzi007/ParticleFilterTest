#ifndef SIMULATION_H
#define SIMULATION_H

#include <QThread>

class Simulation : public QThread
{
public:
    Simulation();

    void run();
};

#endif // SIMULATION_H
