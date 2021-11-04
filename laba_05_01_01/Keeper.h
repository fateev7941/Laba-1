#pragma once
#include <fstream>
#include <string>
#include "List.h"
#include "University.h"
#include "Student.h"
#include "Teacher.h"
#include "AdministrativeStaff.h"
class Keeper
{
private:
	List<University*> universities;

public:
	Keeper();
	~Keeper();
	void add(University* elem);
	void del(size_t position);
	bool save(string file);
	bool load(string file);
	void print();
	size_t size();
};
