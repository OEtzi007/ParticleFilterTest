#ifndef MOTORACTUATOR_H
#define MOTORACTUATOR_H

#include "object.h"

class MotorActuator : public Object
{
public:
	static const double relSigmaV;
	static const double relSigmaOmega;

	MotorActuator(World* const, const CoordinateSystem* const, const Coordinate&);

	double evalLaser(const Laser&) const;
};

#endif // MOTORACTUATOR_H
