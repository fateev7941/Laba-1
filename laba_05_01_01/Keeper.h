#pragma once
#include <fstream>
#include <string>
#include "List.h"
#include "University.h"
class Keeper
{
private:
	List<University*> universities;

public:		
	void add(University* elem);
	void del(size_t position);
	bool save(string file);
	bool load(string file);
	void print();
};

