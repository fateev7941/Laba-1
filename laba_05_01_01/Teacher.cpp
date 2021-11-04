#include "Teacher.h"

Teacher::Teacher(std::string FIO, List<std::string> groups, List<std::string> subjects) :
	University(FIO), groups(groups), subjects(subjects) {
	std::cout << "Teacher(FIO, groups, subjects)\n";
}

Teacher::~Teacher()
{
	std::cout << "~Teacher()\n";
}

std::string Teacher::get_string()
{
	std::string str = "Преподаватель: \n\tФИО: " + FIO + "\n\tгруппы:";
	for (size_t i = 0; i < groups.size(); i++)
		str += "\n\t\t" + groups[i];
	str += "\n\tпредметы: ";
	for (size_t i = 0; i < subjects.size(); i++)
		str += "\n\t\t" + subjects[i];
	str += "\n";
	return str;
}

std::string Teacher::get_string_data()
{
	std::string str = "Teacher\n" + FIO + "\n" + std::to_string(groups.size()) + "\n";
	for (size_t i = 0; i < groups.size(); i++)
		str += groups[i] + "\n";
	str += std::to_string(subjects.size()) + "\n";	
	for (size_t i = 0; i < subjects.size(); i++)
		str += subjects[i] + "\n";
	return str;
}
