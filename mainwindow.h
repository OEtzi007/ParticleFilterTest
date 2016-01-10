#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <thread>
class DataPublisher;
class Simulation;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
private:
	DataPublisher* simulationPublisher;
	Simulation* simulation;
	std::thread* simulationThread;

	void startSimulation();
	void stopSimulation();
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	void setLCDandProgress(int ticks);
private slots:
	void on_runSimulation_button_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
