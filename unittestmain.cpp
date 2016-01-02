#include "unittestcoordinate.h"
#include "unittestvector.h"

int main()
{
	UnitTestCoordinate testCoordinate;
	UnitTestVector testVector;

	QTest::qExec(&testCoordinate);
	QTest::qExec(&testVector);

	return 0;
}
