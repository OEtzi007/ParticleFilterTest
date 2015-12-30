#include "simulatedtestrobot.h"

#include <cmath>
#include "map.h"

SimulatedTestRobot::SimulatedTestRobot(const CoordinateSystem* const base, const Coordinate & origin, const double &radius, const std::string &laserConfigFile):Robot(base, origin, radius, laserConfigFile)
{
}

std::vector<double> SimulatedTestRobot::getNonErrorDistances() const{

}

void SimulatedTestRobot::set(double x, double y, double ori) {
    this->base.x=x;
    this->base.y=y;
    this->base.moveAxes(Vector(this->base.base, std::cos(ori), std::sin(ori)));
}
