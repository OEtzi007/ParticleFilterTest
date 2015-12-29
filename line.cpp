/*
 * Line.cpp
 *
 *  Created on: 27.12.2015
 *      Author: Marvin
 */

#include "line.h"

#include "laser.h"

Line::Line(CoordinateSystem* const base, const Coordinate &start, const Coordinate &end):Object(CoordinateSystem(base,start,end-start)),start(start), end(end) {
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

double Line::evalLaser(const Laser &laser) const {
	Vector lineDir = end-start;
	if(lineDir.getY()*laser.getDirection().getX() == lineDir.getX()*laser.getDirection().getY()) {
		return Laser::range;
	}
	Vector b=start-laser.getOrigin();
	// t*laser.getDirection()-s*lineDir=b
	// =>
	double snumerator = b.getX()*laser.getDirection().getY()-b.getY()*laser.getDirection().getX();
	double denominator = lineDir.getY()*laser.getDirection().getX()-lineDir.getX()*laser.getDirection().getY();
	double s = snumerator/denominator;
	if(s<0 || s>1) {
		return Laser::range;
	}
	double tnumerator = b.getX()*lineDir.getY()-b.getY()*lineDir.getX();
	double t = tnumerator/denominator;
	if(t<0 || t>Laser::range) {
		return Laser::range;
	}
	return t;
}
