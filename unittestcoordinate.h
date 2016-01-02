#ifndef UNITTESTCOORDINATE_H
#define UNITTESTCOORDINATE_H

#include <QObject>

#include <QtTest/QtTest>

class UnitTestCoordinate : public QObject
{
	Q_OBJECT
private slots:
	void constructor() const;
};

#endif // UNITTESTCOORDINATE_H
