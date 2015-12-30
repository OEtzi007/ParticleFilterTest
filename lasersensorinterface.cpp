#include "lasersensorinterface.h"

LaserSensorInterface::LaserSensorInterface()
{

}

std::vector<double> LaserSensorInterface::getSensorData() {
    laserInterfaceMutex.lock();

    laserInterfaceMutex.unlock();
	return std::vector<double>(); //TODO
}
