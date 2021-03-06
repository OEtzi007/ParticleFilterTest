#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(const CoordinateSystem * const base, Coordinate origin, Vector xAxis, Vector yAxis): Coordinate(origin.transform(base)),axis{Vector(base),Vector(base),Vector(base)}
{
	moveAxes(xAxis,yAxis);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, Coordinate origin, Vector xAxis): Coordinate(origin.transform(base)),axis{Vector(base),Vector(base),Vector(base)}{
	moveAxes(xAxis);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, Coordinate origin): Coordinate(origin.transform(base)), axis{Vector(base),Vector(base),Vector(base)}
{
	moveAxes();
}

CoordinateSystem& CoordinateSystem::moveAxes(Vector xAxis,Vector yAxis)
{
	xAxis.transform(base);
	yAxis.transform(base);
	axis[0]=xAxis/xAxis.length();
	axis[2]=cross(xAxis,yAxis);
	axis[2]=axis[2]/axis[2].length();
	axis[1]=cross(axis[2],axis[0]);

	return *this;
}

CoordinateSystem& CoordinateSystem::moveAxes(Vector xAxis)
{
	xAxis.transform(base);
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

	return *this;
}

CoordinateSystem& CoordinateSystem::moveAxes()
{
	axis[0]=Vector(base,1,0,0);
	axis[1]=Vector(base,0,1,0);
	axis[2]=Vector(base,0,0,1);

	return *this;
}
