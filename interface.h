#ifndef INTERFACE_H
#define INTERFACE_H

#include <mutex>
#include <vector>
#include <unordered_map>
#include <string>

class Interface
{
private:
	std::mutex dataLocker;
	std::vector<double> data;
	std::unordered_map<std::string,unsigned int> mappedNames;
public:
	const unsigned int size;

	Interface(const unsigned int& size, const std::vector<std::string>& dataNames);
	Interface(const Interface& interface);
	virtual ~Interface();

	void setAllData(const std::vector<double>& data);
	void setData(const std::string& dataName, const double& data);
	std::vector<double> getAllData();
	double getData(const std::string& dataName);
};

struct Interfaces
{
	Interface laserSensorI;
	Interface motorActuatorI;
	Interface timeI;
};

#endif // INTERFACE_H
