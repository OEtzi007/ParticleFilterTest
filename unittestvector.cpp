#include "unittestvector.h"

#include "vector.h"
#include "coordinatesystem.h"

void UnitTestVector::constructor() const
{
	Vector a(CoordinateSystem::root,1,2,3);
	QVERIFY(a.x == 1);
}
