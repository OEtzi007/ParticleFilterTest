/*
 * Wall.cpp
 *
 *  Created on: 27.12.2015
 *      Author: Marvin
 */

#include "wall.h"

#include "laser.h"
#include "lasersensor.h"

Wall::Wall(CoordinateSystem* const base, const Coordinate& origin, const Vector& normale):Object(CoordinateSystem(base,origin,normale))
{
}

Wall::~Wall()
{
}

/* TODO remove
double Wall::evalLaser(const Laser &laser) const
{
	Vector lineDir = end-start;
	if(lineDir.y*laser.getDirection().x == lineDir.x*laser.getDirection().y) {
		return Laser::range;
	}
	Vector b=start-laser.getOrigin();
	// t*laser.getDirection()-s*lineDir=b
	// =>
	double snumerator = b.x*laser.getDirection().y-b.y*laser.getDirection().x;
	double denominator = lineDir.y*laser.getDirection().x-lineDir.x*laser.getDirection().y;
	double s = snumerator/denominator;
	if(s<0 || s>1) {
		return Laser::range;
	}
	double tnumerator = b.x*lineDir.y-b.y*lineDir.x;
	double t = tnumerator/denominator;
	if(t<0 || t>Laser::range) {
		return Laser::range;
	}
	return t;
}
*/

double Wall::evalLaser(const Laser &laser) const
{
	if(this->base.axes[0]*laser.axes[0]==0){	//wall parallel to laser
		if((this->base-laser)*this->base.axes[0]==0){	//laser completly inside the wall
			return 0;
		} else {	//laser completly outside the wall
			return laser.getRange();
		}
	}

	double intersectionLength=((this->base-Coordinate(this->base.getBase()))*this->base.axes[0])/(laser.axes[0]*this->base.axes[0]);
	if(intersectionLength<0 || intersectionLength>laser.getRange()) {
		return laser.getRange();
	}

	return intersectionLength;
}
