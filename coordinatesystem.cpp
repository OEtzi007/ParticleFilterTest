#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(const CoordinateSystem * const base, Coordinate origin, const Vector &xAxis, const Vector &yAxis): Coordinate(origin.transform(base)),axis{Vector(base),Vector(base),Vector(base)}
{
	axis[0]=xAxis/xAxis.length();
	axis[2]=cross(xAxis,yAxis);
	axis[2]=axis[2]/axis[2].length();
	axis[1]=cross(axis[2],axis[0]);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, const Coordinate& origin, const Vector&xAxis): Coordinate(origin),axis{Vector(base),Vector(base),Vector(base)}{
	axis[0]=xAxis/xAxis.length();
	if(xAxis.z){
		double x=0,y=-1,z;
		//0=xAxis*(x,y,z)=xAxis.x*0+xAxis.y*(-1)+xAxis.z*z
		z=xAxis.y/xAxis.z;
		axis[2]=Vector(base,x,y,z);
		axis[2]=axis[2]/axis[2].length();
	} else {
		axis[2]=Vector(base,0.,0.,1.);
	}
	axis[1]=cross(axis[2],axis[0]);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, const Coordinate& origin): Coordinate(origin), axis{Vector(base),Vector(base),Vector(base)}
{
	//TODO
}