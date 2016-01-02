#ifndef MOTORACTUATOR_H
#define MOTORACTUATOR_H

#include "object.h"

class MotorActuator : public Object
{
public:
	static const double relSigmaV;
	static const double relSigmaOmega;

	MotorActuator(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin);

	double evalLaser(const Laser& laser) const;
};

#endif // MOTORACTUATOR_H
