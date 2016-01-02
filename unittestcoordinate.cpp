#include "unittestcoordinate.h"

#include "coordinate.h"
#include "coordinatesystem.h"

void UnitTestCoordinate::constructor() const
{
	Coordinate a(CoordinateSystem::root,1,2,3);
	QVERIFY(a.x == 1);
	QVERIFY(a.y == 2);
	QCOMPARE(a.z, 3.);
}
