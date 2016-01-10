#ifndef DATAPUBLISHER_H
#define DATAPUBLISHER_H

class MainWindow;

class DataPublisher
{
private:
	unsigned long long int ticks;

	MainWindow* subscriber;
public:
	DataPublisher(MainWindow* const subscriber);

	//setter functions that publish
	void setTicks(unsigned long long int ticks);

	//publisher functions
	void publishTicks() const;
};

#endif // DATAPUBLISHER_H
