#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMutex>
#include <vector>
#include <unordered_map>
#include <string>

class Interface
{
private:
	QMutex dataLocker;
	std::vector<double> data;
	std::unordered_map<std::string,unsigned int> mappedNames;
public:
	const unsigned int size;

	Interface(const unsigned int&, const std::vector<std::string>&);
	virtual ~Interface();

	void setData(const std::vector<double>&);
	std::vector<double> getAllData() const;
	double getData(const std::string&) const;
};

#endif // INTERFACE_H
