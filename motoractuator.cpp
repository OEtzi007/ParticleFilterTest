#include "motoractuator.h"

#include "constants.h"
#include "laser.h"

const double MotorActuator::relSigmaV=REL_SIGMA_V;
const double MotorActuator::relSigmaOmega=REL_SIGMA_OMEGA;

MotorActuator::MotorActuator(const CoordinateSystem* const base, const Coordinate& origin) : Object(CoordinateSystem(base,origin))
{
}

double MotorActuator::evalLaser(const Laser& laser) const
{
	return laser.getRange();
}
