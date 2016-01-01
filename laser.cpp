#include "laser.h"

#include "constants.h"

const double Laser::range=LASER_RANGE;
const double Laser::relSigmaL=REL_SIGMA_L;

Laser::Laser(const CoordinateSystem* const base, Coordinate origin, Vector xAxis, Vector yAxis) : CoordinateSystem(base, origin, xAxis, yAxis)
{

}

Laser::Laser(const CoordinateSystem* const base, Coordinate origin, Vector xAxis) : CoordinateSystem(base, origin, xAxis)
{

}

Laser::Laser(const CoordinateSystem* const base, Coordinate origin) : CoordinateSystem(base, origin)
{

}
