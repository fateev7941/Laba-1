#include "Keeper.h"

Keeper::Keeper()
{
	std::cout << "Keeper()\n";
}

Keeper::~Keeper()
{
	std::cout << "~Keeper()\n";
}

void Keeper::add(University* elem)
{
	universities.push_back(elem);
}

void Keeper::del(size_t position)
{
	delete universities.pop(position);
}

bool Keeper::save(string file)
{
	std::ofstream fout(file);
	if (!fout) return 0;
	fout << to_string(universities.size()) << std::endl;
	for (size_t i = 0; i < universities.size(); ++i)
		fout << universities[i]->get_string_data();

	fout.close();
	return 1;
}

bool Keeper::load(string file)
{
	std::ifstream fin(file);
	if (!fin) return false;

	std::string FIO, type;
	size_t universitie_amount;

	fin >> universitie_amount;
	for (size_t i = 0; i < universitie_amount; i++)
	{
		fin >> type;
		getline(fin, FIO);
		getline(fin, FIO);
		if (type == "Student")
		{
			std::string group, specialty, course, GPA;
			getline(fin, group);
			getline(fin, specialty);
			getline(fin, course);
			getline(fin, GPA);
			universities.push_back(new Student(FIO, group, specialty, course, GPA));
		}
		else if (type == "Teacher")
		{
			std::string buffer;
			List<std::string> groups, subjects;
			size_t group_amount, subject_amount;
			fin >> group_amount;
			getline(fin, buffer);
			for (size_t i = 0; i < group_amount; i++)
			{
				getline(fin, buffer);
				groups.push_back(buffer);
			}
			fin >> subject_amount;
			getline(fin, buffer);
			for (size_t i = 0; i < subject_amount; i++)
			{
				getline(fin, buffer);
				subjects.push_back(buffer);
			}
			universities.push_back(new Teacher(FIO, groups, subjects));
		}
		else if (type == "AdministrativeStaff")
		{
			std::string post, phone, responsibility;
			getline(fin, post);
			getline(fin, phone);
			getline(fin, responsibility);
			universities.push_back(new AdministrativeStaff(FIO, post, phone, responsibility));
		}
	}
	return true;
}

void Keeper::print()
{
	for (size_t i = 0; i < universities.size(); i++)
		std::cout << "ÂÓÇ ¹" << i + 1 << ":\n" << universities[i]->get_string();
}

size_t Keeper::size()
{
	return universities.size();
}