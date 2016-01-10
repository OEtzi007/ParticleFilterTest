#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T11:14:36
#
#-------------------------------------------------

QT		+= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ParticleFilterTest
TEMPLATE = app

SOURCES	+= main.cpp\
	mainwindow.cpp \
	coordinate.cpp \
	coordinatesystem.cpp \
	interface.cpp \
	laser.cpp \
	lasersensor.cpp \
	map.cpp \
	object.cpp \
	robot.cpp \
	robotintelligence.cpp \
	sphere.cpp \
	vector.cpp \
	wall.cpp \
	world.cpp \
	simulation.cpp \
	simulatedtestrobot.cpp \
    motoractuator.cpp \
    constants.cpp \
    datapublisher.cpp

HEADERS	+= mainwindow.h \
	constants.h \
	coordinate.h \
	coordinatesystem.h \
	interface.h \
	laser.h \
	lasersensor.h \
	map.h \
	object.h \
	robot.h \
	robotintelligence.h \
	sphere.h \
	vector.h \
	wall.h \
	world.h \
	simulation.h \
	simulatedtestrobot.h \
    motoractuator.h \
    datapublisher.h

FORMS	+= mainwindow.ui

DISTFILES	+= \
	2D_12.lcfg \
	README.md
