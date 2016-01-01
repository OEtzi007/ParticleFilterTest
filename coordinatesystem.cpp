#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(const CoordinateSystem * const base, Coordinate origin, Vector xAxis, Vector yAxis): Coordinate(origin.transform(base)),axes{Vector(base),Vector(base),Vector(base)}
{
	moveAxes(xAxis,yAxis);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, Coordinate origin, Vector xAxis): Coordinate(origin.transform(base)),axes{Vector(base),Vector(base),Vector(base)}{
	moveAxes(xAxis);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, Coordinate origin): Coordinate(origin.transform(base)), axes{Vector(base),Vector(base),Vector(base)}
{
	moveAxes();
}

CoordinateSystem CoordinateSystem::transform(const CoordinateSystem* const toSystem) const
{
	return CoordinateSystem(toSystem,((Coordinate) *this).transform(toSystem),this->axes[0].transform(toSystem),this->axes[1].transform(toSystem));
}

CoordinateSystem& CoordinateSystem::moveAxes(Vector xAxis,Vector yAxis)
{
	xAxis.transform(base);
	yAxis.transform(base);
	axes[0]=xAxis/xAxis.length();
	axes[2]=cross(xAxis,yAxis);
	axes[2]=axes[2]/axes[2].length();
	axes[1]=cross(axes[2],axes[0]);

	return *this;
}

CoordinateSystem& CoordinateSystem::moveAxes(Vector xAxis)
{
	xAxis.transform(base);
	axes[0]=xAxis/xAxis.length();
	if(xAxis.z){
		double x=0,y=-1,z;
		//0=xAxis*(x,y,z)=xAxis.x*0+xAxis.y*(-1)+xAxis.z*z
		z=xAxis.y/xAxis.z;
		axes[2]=Vector(base,x,y,z);
		axes[2]=axes[2]/axes[2].length();
	} else {
		axes[2]=Vector(base,0.,0.,1.);
	}
	axes[1]=cross(axes[2],axes[0]);

	return *this;
}

CoordinateSystem& CoordinateSystem::moveAxes()
{
	axes[0]=Vector(base,1,0,0);
	axes[1]=Vector(base,0,1,0);
	axes[2]=Vector(base,0,0,1);

	return *this;
}
