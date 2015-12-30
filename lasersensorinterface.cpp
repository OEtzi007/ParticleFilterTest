#include "lasersensorinterface.h"
#include "constants.h"

const double LaserSensorInterface::relSigmaL = REL_SIGMA_L;

LaserSensorInterface::LaserSensorInterface()
{

}

std::vector<double> LaserSensorInterface::getSensorData() {
    laserInterfaceMutex.lock();

    laserInterfaceMutex.unlock();
	return std::vector<double>(); //TODO
}

unsigned int LaserSensorInterface::getMeasurementId() const{
    //TODO
}
