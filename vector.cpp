#include "vector.h"

#include <cmath>
#include <cassert>	//TODO
#include "coordinatesystem.h"

Vector::Vector(const CoordinateSystem* const base, const double &x, const double &y, const double &z):Coordinate(base,x,y,z)
{
}


Vector& Vector::transform(const CoordinateSystem* const toSystem)
{
	if(toSystem==this->base)
		return *this;
	bool goDownTransformTree=false;
	const CoordinateSystem* preSystem=toSystem;
	const CoordinateSystem* curSystem=preSystem->getBase();
	while(curSystem){
		if(curSystem==this->base){
			goDownTransformTree=true;
			break;
		}
		preSystem=curSystem;
		curSystem=preSystem->getBase();
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

		//three lines for transformation
		Vector newVec(localToSystem,this->x,this->y,this->z);
		newVec=newVec.x*transformedAxis[0]+newVec.y*transformedAxis[1]+newVec.z*transformedAxis[2];
		*this=newVec;

		this->transform(toSystem);
	} else {	//go up the transformation tree
		const CoordinateSystem* const localToSystem=this->base->getBase();
		if(localToSystem==0){	//this actually shouldn't happen, so assert
			assert(localToSystem==0);	//TODO
			this->base=preSystem;	//if above happens, this could fix correctly
		}
		//one lines for transformation
		*this=this->x*this->base->axis[0]+this->y*this->base->axis[1]+this->z*this->base->axis[2];

		this->transform(toSystem);
	}
	return *this;
}

double Vector::length() const
{
	return sqrt((*this)*(*this));
}

Vector operator+(const Vector& a, Vector b)
{
	b.transform(a.base);
	return Vector(a.base,a.x+b.x,a.y+b.y,a.z+b.z);
}

Coordinate operator+(const Coordinate& coo, Vector vec){
	vec.transform(coo.base);
	return Coordinate(coo.getBase(),coo.x+vec.x,coo.y+vec.y,coo.z+vec.z);
}

Coordinate operator+(Vector vec, const Coordinate& coo){
	vec.transform(coo.base);
	return Coordinate(coo.getBase(),coo.x+vec.x,coo.y+vec.y,coo.z+vec.z);
}

Vector operator*(const double& s, const Vector& vec){
	return Vector(vec.getBase(),s*vec.x,s*vec.y,s*vec.z);
}

Vector operator*(const Vector& vec, const double& s){
	return Vector(vec.getBase(),s*vec.x,s*vec.y,s*vec.z);
}

Vector operator/(const Vector& vec, const double& s)
{
	return Vector(vec.getBase(),vec.x/s,vec.y/s,vec.z/s);
}

double operator*(const Vector& u, Vector v){
	v.transform(u.getBase());
	return u.x*v.x+u.y*v.y+u.z*v.z;
}

Vector cross(const Vector& a, Vector b){
	b.transform(a.getBase());
	return Vector(a.getBase(),a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
