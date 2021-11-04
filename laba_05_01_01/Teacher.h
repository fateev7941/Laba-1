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
    Teacher(std::string FIO, List<std::string> groups, List<std::string> subjects);
    ~Teacher();
    std::string get_string() override;
    std::string get_string_data() override;
};
