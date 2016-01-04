#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "simulation.h"

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
	Simulation sim;
	connect(&sim,
			SIGNAL(itTicked(int)),
			this,
			SLOT(setLCDandProgress(int)),
			Qt::BlockingQueuedConnection);
	sim.start();
	sim.wait();
}

void MainWindow::setLCDandProgress(int tick)
{
	ui->progressBar->setMaximum(TOTAL_TICKS);
	ui->progressBar->setValue(tick);
	ui->lcdNumber->display((int)tick);
	this->show();
}
