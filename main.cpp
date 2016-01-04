#include "mainwindow.h"
#include <QApplication>

#include "simulation.h"

int main(/*int argc, char *argv[]*/)
{
	/*
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	*/
	Simulation sim;
	sim.start();
	sim.wait();

	//return a.exec();
	return 0;
}
