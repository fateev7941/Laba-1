#pragma once
#include <string>
#include "List.h"
#include "University.h"
class Teacher :
    public University
{
private:
    List<std::string> groups, subjects;

public:
    std::string get_string() override;
};

