#ifndef TIMEINTERFACE_H
#define TIMEINTERFACE_H

#include "interface.h"

class TimeInterface : public Interface
{
private:
public:
	TimeInterface();
    double getTime() const;
};

#endif // TIMEINTERFACE_H
