#include "lasersensorinterface.h"
#include "constants.h"

const double LaserSensorInterface::relSigmaL = REL_SIGMA_L;

LaserSensorInterface::LaserSensorInterface():Interface(0,std::vector<std::string>()) //TODO remove this whole class
{
}

std::vector<double> LaserSensorInterface::getSensorData(){
	laserInterfaceMutex.lock();

	laserInterfaceMutex.unlock();
	return std::vector<double>(); //TODO
}

unsigned int LaserSensorInterface::getMeasurementId() const{
	//TODO
	return 0;
}
