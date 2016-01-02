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
	Wall(World* const world, const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& normale);
	virtual ~Wall();

	double evalLaser(const Laser& laser) const;
};

#endif /* WALL_H_ */
