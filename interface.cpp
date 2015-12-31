#include "interface.h"

#include <cassert>	//TODO assert

Interface::Interface(const unsigned int& size, const std::vector<std::string>& dataNames):data(size),mappedNames(),size(size)
{
	assert(dataNames.size()==size);	//TODO assert
	for(unsigned int i=0;i<size;i++)
		mappedNames.insert({dataNames[i],i});
}

Interface::~Interface()
{
}

void Interface::setData(const std::vector<double> & insertData)
{
	assert(insertData.size()==size);	//TODO assert
	data=insertData;
}

std::vector<double> Interface::getAllData() const
{
	return data;
}

double Interface::getData(const std::string& dataName) const
{
	return data[mappedNames.at(dataName)];
}
