#ifndef LASERSENSORINTERFACE_H
#define LASERSENSORINTERFACE_H

#include "interface.h"

#include <vector>

class LaserSensorInterface : public Interface
{
public:
	LaserSensorInterface();

	std::vector<double> getSensorData() const;
    unsigned int getMeasurementId() const;
};

#endif // LASERSENSORINTERFACE_H
