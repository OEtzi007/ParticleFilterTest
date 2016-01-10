#include "thread.h"

Thread::Thread():
	shutDownFlag(false),
	isRunning(false)
{

}

void Thread::shutDown()
{
	shutDownFlag=true;
}
