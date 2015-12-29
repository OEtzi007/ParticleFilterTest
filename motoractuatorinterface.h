#ifndef MOTORACTUATORINTERFACE_H
#define MOTORACTUATORINTERFACE_H

#include "interface.h"
#include "vector.h"

class MotorActuatorInterface : public Interface
{
public:
    static const double relSigmaV;
    static const double sigmaOmega;

	MotorActuatorInterface();

    Vector getVelocity() const;
    double getOmega() const;
};

#endif // MOTORACTUATORINTERFACE_H
