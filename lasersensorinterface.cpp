#include "lasersensorinterface.h"
#include "constants.h"

const double LaserSensorInterface::relSigmaL = REL_SIGMA_L;

LaserSensorInterface::LaserSensorInterface()
{

}

std::vector<double> LaserSensorInterface::getSensorData() const{
	return std::vector<double>(); //TODO
}
