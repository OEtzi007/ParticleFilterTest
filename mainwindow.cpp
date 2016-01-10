#include "mainwindow.h"
#include "ui_mainwindow.h"

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
	delete ui;
}

void MainWindow::on_runSimulation_button_clicked()
{
	DataPublisher simulation(this);
	Simulation sim(&simulation);
	sim.run();
}

void MainWindow::setLCDandProgress(int ticks)
{
	ui->progressBar->setMaximum(TOTAL_TICKS);
	ui->progressBar->setValue(ticks);
	ui->lcdNumber->display(ticks);
	this->updatesEnabled();
	this->update();
}
