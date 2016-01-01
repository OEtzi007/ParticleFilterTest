#include "motoractuatorinterface.h"

#include "constants.h"
#include "coordinatesystem.h"

const double MotorActuatorInterface::relSigmaV = REL_SIGMA_V;
const double MotorActuatorInterface::relSigmaOmega = REL_SIGMA_OMEGA;

MotorActuatorInterface::MotorActuatorInterface()
{

}

Vector MotorActuatorInterface::getVelocity() const{
    return Vector(0); //TODO
}

double MotorActuatorInterface::getOmega() const{
    return 0; //TODO
}
