#include "datapublisher.h"

#include "mainwindow.h"

DataPublisher::DataPublisher(MainWindow* const subscriber):
	subscriber(subscriber)
{

}

void DataPublisher::setTicks(unsigned long long ticks)
{
	objectMutex.lock();
	this->ticks=ticks;
	this->publishTicks();
	objectMutex.unlock();
}

void DataPublisher::publishTicks()
{
	subscriber->setLCDandProgress(ticks);
}
