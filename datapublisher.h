#ifndef DATAPUBLISHER_H
#define DATAPUBLISHER_H

#include <thread>

class MainWindow;

class DataPublisher
{
private:
	std::mutex objectMutex;

	unsigned long long int ticks;

	MainWindow* subscriber;
public:
	DataPublisher(MainWindow* const subscriber);

	//setter functions that publish
	void setTicks(unsigned long long int ticks);

	//publisher functions
	void publishTicks();
};

#endif // DATAPUBLISHER_H
