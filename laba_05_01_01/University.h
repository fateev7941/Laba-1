#pragma once
#include <iostream>
#include <string>
class University
{
protected:
	std::string FIO;

public:
	University(std::string FIO);
	virtual ~University();
	virtual std::string get_string() = 0;
	virtual std::string get_string_data() = 0;
};
