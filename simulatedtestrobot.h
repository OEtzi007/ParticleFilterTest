#ifndef SIMULATEDTESTROBOT_H
#define SIMULATEDTESTROBOT_H

#include <robot.h>

class SimulatedTestRobot : public Robot
{
public:
    SimulatedTestRobot();

    std::vector<double> getNonErrorDistances() const; //TODO Abstände von LaserSensoren zurückgeben
    void set(double, double, double);
};

#endif // SIMULATEDTESTROBOT_H
