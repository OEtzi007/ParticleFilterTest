/*
 * Line.h
 *
 *  Created on: 27.12.2015
 *      Author: Marvin
 */

#ifndef LINE_H_
#define LINE_H_

#include "mapobject.h"

#include "coordinate.h";

class Line: public MapObject {
private:
	Coordinate start;
	Coordinate end;
public:
	Line(const Coordinate&, const Coordinate&);
	virtual ~Line();
	double evalLaser(const Laser&) const;
};

#endif /* LINE_H_ */
