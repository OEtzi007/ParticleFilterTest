#ifndef THREAD_H
#define THREAD_H


class Thread
{
protected:
	bool shutDownFlag;
	bool isRunning;
public:
	Thread();

	virtual void run()=0;
	void shutDown();
};

#endif // THREAD_H
