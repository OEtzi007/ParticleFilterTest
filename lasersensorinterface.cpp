#include "lasersensorinterface.h"

const double LaserSensorInterface::relSigmaL = REL_SIGMA_L;

LaserSensorInterface::LaserSensorInterface()
{

}

std::vector<double> LaserSensorInterface::getSensorData() const{
	return std::vector<double>(); //TODO
}

unsigned int LaserSensorInterface::getMeasurementId() const{
    //TODO
}
