#include "Student.h"

Student::Student(std::string FIO, std::string group, std::string specialty, std::string course, std::string GPA) :
	University(FIO), group(group), specialty(specialty), course(course), GPA(GPA) {
	std::cout << "Student(FIO, group, specialty, course, GPA)\n";
}

Student::~Student()
{
	std::cout << "~Student()\n";
}

std::string Student::get_string()
{
	return "Студент: \n\tФИО: " + FIO +
		"\n\tгруппа: " + group +
		"\n\tспециальность: " + specialty +
		"\n\tкурс: " + course +
		"\n\tсредний балл: " + GPA + "\n";
}

std::string Student::get_string_data()
{
	return "Student\n" +
		FIO + "\n" +
		group + "\n" +
		specialty + "\n" +
		course + "\n" +
		GPA + "\n";
}
