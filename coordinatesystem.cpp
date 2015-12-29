#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(CoordinateSystem * const base,const Coordinate& origin, const Vector &xAxis, const Vector &yAxis): Coordinate(origin),base(base),axis()
{
	axis[0]=xAxis/xAxis.length();
	axis[2]=cross(xAxis,yAxis);
	axis[2]=axis[2]/axis[2].length();
	axis[1]=cross(axis[2],axis[0]);
}

CoordinateSystem::CoordinateSystem(CoordinateSystem* const base, const Coordinate& origin, const Vector&xAxis): Coordinate(origin),base(base),axis(){
	axis[0]=xAxis/xAxis.length();
	if(xAxis.getZ()){
		double x=0,y=-1,z;
		//0=xAxis*(x,y,z)=xAxis.x*0+xAxis.y*(-1)+xAxis.z*z
		z=xAxis.getY()/xAxis.getZ();
		axis[2]=Vector(x,y,z);
		axis[2]=axis[2]/axis[2].length();
	} else {
		axis[2]=Vector(0.,0.,1.);
	}
	axis[1]=cross(axis[2],axis[0]);
}
