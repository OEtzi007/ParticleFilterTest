/*
 * Wall.h
 *
 *  Created on: 27.12.2015
 *      Author: Marvin
 */

#ifndef WALL_H_
#define WALL_H_

#include "object.h"

#include "coordinate.h"

class Wall: public Object {
public:
	Wall(World* const, CoordinateSystem* const, const Coordinate&, const Vector&);
	virtual ~Wall();
	double evalLaser(const Laser&) const;
};

#endif /* WALL_H_ */
