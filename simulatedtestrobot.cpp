#include "simulatedtestrobot.h"

#include "map.h"

SimulatedTestRobot::SimulatedTestRobot() : Robot(Map::base, Coordinate(Map::base))
{

}

void SimulatedTestRobot::set(double x, double y, double ori) {
    this->base.x=x;
    this->base.y=y;
    this->base.transform(ori);
}
