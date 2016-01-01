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

	LaserSensor(World* const, const CoordinateSystem* const, const Coordinate&, const Vector&);

	double getMeasurement() const;
	double evalLaser(const Laser&) const;
};

#endif // LASERSENSOR_H
