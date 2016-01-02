#ifndef UNITTESTVECTOR_H
#define UNITTESTVECTOR_H

#include <QObject>

#include <QtTest/QtTest>

class UnitTestVector : public QObject
{
	Q_OBJECT
private slots:
	void constructor() const;
};

#endif // UNITTESTVECTOR_H
