#ifndef SIMULATEDTESTROBOT_H
#define SIMULATEDTESTROBOT_H

#include <robot.h>

class SimulatedTestRobot : public Robot
{
public:
    SimulatedTestRobot() = delete;
    SimulatedTestRobot(const CoordinateSystem* const, const Coordinate&, const double& radius=ROBOT_RADIUS, const std::string& laserConfigFile=LASER_CONFIG_FILE);

    std::vector<double> getNonErrorDistances() const; //TODO Abstände von LaserSensoren zurückgeben
    void set(double, double, double);
};

#endif // SIMULATEDTESTROBOT_H
