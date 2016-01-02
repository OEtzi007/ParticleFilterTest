#include "coordinate.h"

#include <cassert>	//TODO
#include "vector.h"
#include "coordinatesystem.h"

Coordinate::Coordinate(const CoordinateSystem* const refBase, const double &x, const double &y, const double &z):refBase(refBase),x(x),y(y),z(z)
{
}

Coordinate Coordinate::transform(const CoordinateSystem* const toSystem) const
{
	if(toSystem==this->refBase)
		return *this;
	bool goDownTransformTree=false;
	const CoordinateSystem* preSystem=toSystem;
	const CoordinateSystem* curSystem=preSystem->refBase;
	while(curSystem){
		if(curSystem==this->refBase){
			goDownTransformTree=true;
			break;
		}
		preSystem=curSystem;
		curSystem=preSystem->refBase;
	}
	if(goDownTransformTree || this->refBase==0){	//go down the transform tree
		const CoordinateSystem* const localToSystem=preSystem;
		Vector transformedAxes[3]={Vector(localToSystem,
								   localToSystem->axes[0].x,
								   localToSystem->axes[1].x,
								   localToSystem->axes[2].x),
								   Vector(localToSystem,
								   localToSystem->axes[0].y,
								   localToSystem->axes[1].y,
								   localToSystem->axes[2].y),
								   Vector(localToSystem,
								   localToSystem->axes[0].z,
								   localToSystem->axes[1].z,
								   localToSystem->axes[2].z)};

		//two lines for transformation
		Coordinate result(localToSystem,this->x-localToSystem->x,this->y-localToSystem->y,this->z-localToSystem->z);
		result=result.x*transformedAxes[0]+result.y*transformedAxes[1]+result.z*transformedAxes[2];

		return result.transform(toSystem);
	} else {	//go up the transformation tree
		const CoordinateSystem* const localToSystem=this->refBase->refBase;
		if(localToSystem==0){	//this actually shouldn't happen, so assert
			assert(localToSystem==0);	//TODO assert
			Coordinate result(*this);
			result.refBase=preSystem;	//if above happens, this could fix correctly
			return result.transform(toSystem);
		}
		//two lines for transformation
		Coordinate result(localToSystem,this->refBase->x,this->refBase->y,this->refBase->z);
		result=result+this->x*this->refBase->axes[0]+this->y*this->refBase->axes[1]+this->z*this->refBase->axes[2];

		return result.transform(toSystem);
	}
	assert(false);	//TODO assert
	return Coordinate(toSystem);
}

const CoordinateSystem* Coordinate::getBase() const
{
	return refBase;
}

Vector operator-(const Coordinate& a, const Coordinate& b){
	Coordinate a_=a.transform(b.refBase);
	return Vector(b.refBase,a_.x-b.x,a_.y-b.y,a_.z-b.z);
}
