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
	LaserSensorInterface();

    std::vector<double> getSensorData();
};

#endif // LASERSENSORINTERFACE_H
