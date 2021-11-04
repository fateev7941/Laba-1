#pragma once
#include <string>
#include "University.h"
class Student :
    public University
{
private:
    std::string group, specialty, course, GPA;

public:
    std::string get_string() override;
};

