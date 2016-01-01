#include "coordinate.h"

#include <cassert>	//TODO
#include "vector.h"
#include "coordinatesystem.h"

Coordinate::Coordinate(const CoordinateSystem* const base, const double &x, const double &y, const double &z):base(base),x(x),y(y),z(z)
{
}

Coordinate Coordinate::transform(const CoordinateSystem* const toSystem) const
{
	if(toSystem==this->base)
		return *this;
	bool goDownTransformTree=false;
	const CoordinateSystem* preSystem=toSystem;
	const CoordinateSystem* curSystem=preSystem->base;
	while(curSystem){
		if(curSystem==this->base){
			goDownTransformTree=true;
			break;
		}
		preSystem=curSystem;
		curSystem=preSystem->base;
	}
	if(goDownTransformTree || this->base==0){	//go down the transform tree
		const CoordinateSystem* const localToSystem=preSystem;
		Vector transformedAxis[3]={Vector(localToSystem,
								   localToSystem->axis[0].x,
								   localToSystem->axis[1].x,
								   localToSystem->axis[2].x),
								   Vector(localToSystem,
								   localToSystem->axis[0].y,
								   localToSystem->axis[1].y,
								   localToSystem->axis[2].y),
								   Vector(localToSystem,
								   localToSystem->axis[0].z,
								   localToSystem->axis[1].z,
								   localToSystem->axis[2].z)};

		//two lines for transformation
		Coordinate result(localToSystem,this->x-localToSystem->x,this->y-localToSystem->y,this->z-localToSystem->z);
		result=result.x*transformedAxis[0]+result.y*transformedAxis[1]+result.z*transformedAxis[2];

		return result.transform(toSystem);
	} else {	//go up the transformation tree
		const CoordinateSystem* const localToSystem=this->base->base;
		if(localToSystem==0){	//this actually shouldn't happen, so assert
			assert(localToSystem==0);	//TODO assert
			Coordinate result(*this);
			result.base=preSystem;	//if above happens, this could fix correctly
			return result.transform(toSystem);
		}
		//two lines for transformation
		Coordinate result(localToSystem,this->base->x,this->base->y,this->base->z);
		result=result+this->x*this->base->axis[0]+this->y*this->base->axis[1]+this->z*this->base->axis[2];

		return result.transform(toSystem);
	}
	assert(false);	//TODO assert
	return Coordinate(toSystem);
}

const CoordinateSystem* Coordinate::getBase() const
{
	return base;
}

Vector operator-(Coordinate a, const Coordinate& b){
	a.transform(b.base);
	return Vector(b.base,a.x-b.x,a.y-b.y,a.z-b.z);
}
