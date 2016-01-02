#ifndef LASERSENSOR_H
#define LASERSENSOR_H

#include "object.h"

#include "coordinatesystem.h"

class LaserSensor : public Object
{
public:
	static const double range;
	static const double relSigmaL;
	static const double sigmaTheta;
	static const double errorProbability;

	LaserSensor(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& direction);

	double getMeasurement() const;
	double getNonErrorMeasurement() const; //TODO remove later
	double evalLaser(const Laser& laser) const;
};

#endif // LASERSENSOR_H
