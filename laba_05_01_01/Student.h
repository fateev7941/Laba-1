#pragma once
#include <string>
#include "University.h"
class Student :
    public University
{
private:
    std::string group, specialty, course, GPA;

public:
    Student(std::string FIO, std::string group, std::string specialty, std::string course, std::string GPA);
    ~Student();
    std::string get_string() override;
    std::string get_string_data() override;
};
