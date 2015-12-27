#ifndef MAPOBJECT_H
#define MAPOBJECT_H

class Laser;

class MapObject
{
public:
	MapObject();
	virtual double evalLaser(const Laser&) const = 0;
};

#endif // MAPOBJECT_H
