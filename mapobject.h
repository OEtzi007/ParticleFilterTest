#ifndef MAPOBJECT_H
#define MAPOBJECT_H


class MapObject
{
public:
	MapObject();
	double evalLaser(const Laser&) const = 0;
};

#endif // MAPOBJECT_H
