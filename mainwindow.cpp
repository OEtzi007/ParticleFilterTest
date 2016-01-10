#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <thread>
#include "simulation.h"
#include "datapublisher.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	stopSimulation();
	delete ui;
}

void MainWindow::on_runSimulation_button_clicked()
{
	startSimulation();
}

void MainWindow::setLCDandProgress(int ticks)
{
	ui->progressBar->setMaximum(TOTAL_TICKS);
	ui->progressBar->setValue(ticks);
	ui->lcdNumber->display(ticks);
	this->updatesEnabled();
	this->update();
}

void MainWindow::startSimulation()
{
	simulationPublisher=new DataPublisher(this);
	simulation=new Simulation(simulationPublisher);
	simulationThread=new std::thread(&Simulation::run,simulation);
}

void MainWindow::stopSimulation()
{
	simulation->shutDown();
	simulationThread->join();
}
