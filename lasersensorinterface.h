#ifndef LASERSENSORINTERFACE_H
#define LASERSENSORINTERFACE_H

#include "interface.h"

#include <vector>
#include <QtCore>

class LaserSensorInterface : public Interface
{
private:
	QWaitCondition busy;
	QMutex laserInterfaceMutex;
public:
	static const double relSigmaL;

	LaserSensorInterface();

	std::vector<double> getSensorData();
	unsigned int getMeasurementId() const;
};

#endif // LASERSENSORINTERFACE_H
