#pragma once
#include <string>
class University
{
protected:
	std::string FIO;

public:
	virtual std::string get_string() = 0;
};

