#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(const CoordinateSystem * const base, const Coordinate& origin, const Vector& xAxis, const Vector& yAxis): Coordinate(origin.transform(base)),axes{Vector(base),Vector(base),Vector(base)}
{
	moveAxes(xAxis,yAxis);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, const Coordinate& origin, const Vector& xAxis): Coordinate(origin.transform(base)),axes{Vector(base),Vector(base),Vector(base)}{
	moveAxes(xAxis);
}

CoordinateSystem::CoordinateSystem(const CoordinateSystem* const base, const Coordinate& origin): Coordinate(origin.transform(base)), axes{Vector(base),Vector(base),Vector(base)}
{
	moveAxes();
}

CoordinateSystem CoordinateSystem::transform(const CoordinateSystem* const toSystem) const
{
	return CoordinateSystem(toSystem,((Coordinate) *this).transform(toSystem),this->axes[0].transform(toSystem),this->axes[1].transform(toSystem));
}

CoordinateSystem& CoordinateSystem::moveAxes(const Vector& xAxis, const Vector& yAxis)
{
	Vector x=xAxis.transform(base);
	Vector y=yAxis.transform(base);
	axes[0]=x/x.length();
	axes[2]=cross(x,y);
	axes[2]=axes[2]/axes[2].length();
	axes[1]=cross(axes[2],axes[0]);

	return *this;
}

CoordinateSystem& CoordinateSystem::moveAxes(const Vector& xAxis)
{
	Vector xAx=xAxis.transform(base);
	axes[0]=xAx/xAx.length();
	if(xAx.z){
		double x=0,y=-1,z;
		//0=xAxis*(x,y,z)=xAxis.x*0+xAxis.y*(-1)+xAxis.z*z
		z=xAx.y/xAx.z;
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
