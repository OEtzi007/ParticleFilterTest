#include "motoractuatorinterface.h"
#include "constants.h"

#include "coordinatesystem.h"

const double MotorActuatorInterface::relSigmaV = REL_SIGMA_V;
const double MotorActuatorInterface::sigmaOmega = SIGMA_OMEGA;

MotorActuatorInterface::MotorActuatorInterface(): Interface(0,std::vector<std::string>())	//TODO remove this whole class
{

}

Vector MotorActuatorInterface::getVelocity() const{
    return Vector(0); //TODO
}

double MotorActuatorInterface::getOmega() const{
    return 0;
}
