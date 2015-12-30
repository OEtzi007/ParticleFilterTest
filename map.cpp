#include "map.h"

#include "constants.h"

const Coordinate Map::origin(0,MAP_XORIGIN,MAP_YORIGIN,MAP_ZORIGIN);
const double Map::width=MAP_WIDTH;
const double Map::height=MAP_HEIGHT;
const CoordinateSystem* const Map::base=MAP_BASESYSTEM;

Map::Map()
{

}
