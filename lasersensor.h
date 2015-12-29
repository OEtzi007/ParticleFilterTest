#ifndef LASERSENSOR_H
#define LASERSENSOR_H

#include "object.h"

#include "coordinatesystem.h"

class LaserSensor : public Object
{
public:
	LaserSensor(const CoordinateSystem&);

	double evalLaser(const Laser&) const;
};

#endif // LASERSENSOR_H
