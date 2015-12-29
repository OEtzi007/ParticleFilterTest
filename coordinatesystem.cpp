#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(CoordinateSystem * const base,const Coordinate& origin, const Vector &, const Vector &): Coordinate(origin),base(base),axis()
{

}
