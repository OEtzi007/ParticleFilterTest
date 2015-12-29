/*
 * Line.h
 *
 *  Created on: 27.12.2015
 *      Author: Marvin
 */

#ifndef LINE_H_
#define LINE_H_

#include "object.h"

#include "coordinate.h"

class Line: public Object {
private:
	Coordinate start;
	Coordinate end;
public:
	Line(CoordinateSystem* const, const Coordinate&, const Coordinate&);
	virtual ~Line();
	double evalLaser(const Laser&) const;
};

#endif /* LINE_H_ */
