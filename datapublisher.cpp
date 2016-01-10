#include "datapublisher.h"

#include "mainwindow.h"

DataPublisher::DataPublisher(MainWindow* const subscriber):
	subscriber(subscriber)
{

}

void DataPublisher::setTicks(unsigned long long ticks)
{
	this->ticks=ticks;
	this->publishTicks();
}

void DataPublisher::publishTicks() const
{
	subscriber->setLCDandProgress(ticks);
}
