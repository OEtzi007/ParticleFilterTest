#include "coordinatesystem.h"

//#define DEBUG

#ifdef DEBUG
#include <cassert>	//NOTE assert
#include <iostream>	//NOTE io
#endif

bool CoordinateSystem::rootExists=false;
const CoordinateSystem* const CoordinateSystem::root=new CoordinateSystem(0,Coordinate(0));

CoordinateSystem::CoordinateSystem(const CoordinateSystem * const refBase, const Coordinate& origin, const Vector& xAxis, const Vector& yAxis):
	Coordinate(origin.transform(refBase)),
	axes{Vector(refBase),
		 Vector(refBase),
		 Vector(refBase)}
{
#ifdef DEBUG
	if(refBase==0){
		assert(!rootExists);	//NOTE assert
		rootExists=true;
		std::cout << "root pointer is:\t" << this << std::endl;	//NOTE io
	}
#endif

	moveAxes(xAxis,yAxis);

#ifdef DEBUG
	//NOTE io whole section
	const CoordinateSystem* cur=this;
	while(cur){
		std::cout << cur << std::endl << "|" << std::endl << "V" << std::endl;
		cur=cur->refBase;
	}
	std::cout << "0" << std::endl << std::endl;
#endif
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const refBase, const Coordinate& origin, const Vector& xAxis):
	Coordinate(origin.transform(refBase)),
	axes{Vector(refBase),
		 Vector(refBase),
		 Vector(refBase)}
{
#ifdef DEBUG
	if(refBase==0){
		assert(!rootExists);	//NOTE assert
		rootExists=true;
		std::cout << "root pointer is:\t" << this << std::endl;	//NOTE io
	}
#endif

	moveAxes(xAxis);

#ifdef DEBUG
	//NOTE io whole section
	const CoordinateSystem* cur=this;
	while(cur){
		std::cout << cur << std::endl << "|" << std::endl << "V" << std::endl;
		cur=cur->refBase;
	}
	std::cout << "0" << std::endl << std::endl;
#endif
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const refBase, const Coordinate& origin):
	Coordinate(origin.transform(refBase)),
	axes{Vector(refBase),
		 Vector(refBase),
		 Vector(refBase)}
{
#ifdef DEBUG
	if(refBase==0){
		assert(!rootExists);	//NOTE assert
		rootExists=true;
		std::cout << "root pointer is:\t" << this << std::endl;	//NOTE io
	}
#endif

	moveAxes();

#ifdef DEBUG
	//NOTE io whole section
	const CoordinateSystem* cur=this;
	while(cur){
		std::cout << cur << std::endl << "|" << std::endl << "V" << std::endl;
		cur=cur->refBase;
	}
	std::cout << "0" << std::endl << std::endl;
#endif
}

CoordinateSystem::~CoordinateSystem()
{
#ifdef DEBUG
	if(refBase==0){
		assert(rootExists);	//NOTE assert
		rootExists=false;
	}
#endif
}

CoordinateSystem CoordinateSystem::transform(const CoordinateSystem* const toSystem) const
{
	return CoordinateSystem(toSystem,((Coordinate) *this).transform(toSystem),this->axes[0].transform(toSystem),this->axes[1].transform(toSystem));
}

CoordinateSystem& CoordinateSystem::moveAxes(const Vector& xAxis, const Vector& yAxis)
{
	Vector x=xAxis.transform(refBase);
	Vector y=yAxis.transform(refBase);
	axes[0]=x/x.length();
	axes[2]=cross(x,y);
	axes[2]=axes[2]/axes[2].length();
	axes[1]=cross(axes[2],axes[0]);

	return *this;
}

CoordinateSystem& CoordinateSystem::moveAxes(const Vector& xAxis)
{
	Vector xAx=xAxis.transform(refBase);
	axes[0]=xAx/xAx.length();
	if(xAx.z){
		double x=0,y=-1,z;
		//0=xAxis*(x,y,z)=xAxis.x*0+xAxis.y*(-1)+xAxis.z*z
		z=xAx.y/xAx.z;
		axes[2]=Vector(refBase,x,y,z);
		axes[2]=axes[2]/axes[2].length();
	} else {
		axes[2]=Vector(refBase,0.,0.,1.);
	}
	axes[1]=cross(axes[2],axes[0]);

	return *this;
}

CoordinateSystem& CoordinateSystem::moveAxes()
{
	axes[0]=Vector(refBase,1,0,0);
	axes[1]=Vector(refBase,0,1,0);
	axes[2]=Vector(refBase,0,0,1);

	return *this;
}
