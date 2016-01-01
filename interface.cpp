#include "interface.h"

#include <cassert>	//TODO assert

Interface::Interface(const unsigned int& size, const std::vector<std::string>& dataNames):data(size),mappedNames(),size(size)
{
	assert(dataNames.size()==size);	//TODO assert
	for(unsigned int i=0;i<size;i++)
		mappedNames.insert({dataNames[i],i});
}

Interface::Interface(const Interface& toCopy):data(toCopy.data),mappedNames(toCopy.mappedNames),size(toCopy.size)
{
}

Interface::~Interface()
{
}

void Interface::setData(const std::vector<double> & insertData)
{
	dataLocker.lock();
	assert(insertData.size()==size);	//TODO assert
	data=insertData;
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
