#include <iostream>
#include <string>
#include "Station.h"

using namespace std;

namespace w2
{
	Station::Station()
	: _name("")
	{
		_numPasses[0] = 0;
		_numPasses[1] = 0;
	}

	void Station::set(const std::string& name, unsigned student, unsigned adult)
	{
		_name = name;
		_numPasses[ADULT_PASS] = adult;
		_numPasses[STUDENT_PASS] = student;
	}

	void Station::update(PassType type, int number)
	{
		_numPasses[type] += number;
	}

	unsigned Station::inStock(PassType type) const
	{
		return _numPasses[type];
	}

	const std::string& Station::getName() const
	{
		return _name;
	}
}
