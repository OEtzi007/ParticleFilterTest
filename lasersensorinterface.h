#ifndef LASERSENSORINTERFACE_H
#define LASERSENSORINTERFACE_H

#include "interface.h"

#include <vector>

class LaserSensorInterface : public Interface
{
public:
    static const double relSigmaL;

	LaserSensorInterface();

	std::vector<double> getSensorData() const;
    unsigned int getMeasurementId() const;
};

#endif // LASERSENSORINTERFACE_H
