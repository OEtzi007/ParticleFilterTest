#include "interface.h"

#ifdef DEBUG
#include <cassert>	//NOTE assert
#endif

Interface::Interface(const unsigned int& size, const std::vector<std::string>& dataNames):
	data(size),
	mappedNames(),
	size(size)
{
#ifdef DEBUG
	assert(dataNames.size()==size);	//NOTE assert
#endif
	for(unsigned int i=0;i<size;i++)
		mappedNames.insert({dataNames[i],i});
}

Interface::Interface(const Interface& interface):
	data(interface.data),
	mappedNames(interface.mappedNames),
	size(interface.size)
{
}

Interface::~Interface()
{
}

void Interface::setData(const std::vector<double>& data)
{
	dataLocker.lock();
#ifdef DEBUG
	assert(data.size()==size);	//NOTE assert
#endif
	this->data=data;
	dataLocker.unlock();
}

std::vector<double> Interface::getAllData()
{
	dataLocker.lock();
	std::vector<double> copy(data);
	dataLocker.unlock();
	return copy;
}

double Interface::getData(const std::string& dataName)
{
	dataLocker.lock();
	double result=data[mappedNames.at(dataName)];
	dataLocker.unlock();
	return result;
}
