#include "motoractuator.h"

#include "constants.h"
#include "laser.h"

const double MotorActuator::relSigmaV=REL_SIGMA_V;
const double MotorActuator::relSigmaOmega=REL_SIGMA_OMEGA;

MotorActuator::MotorActuator(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin) : Object(world, CoordinateSystem(refBase,origin))
{
}

double MotorActuator::evalLaser(const Laser& laser) const
{
	return laser.getRange();
}
