#pragma once
#include <string>
#include "University.h"
class AdministrativeStaff :
    public University
{
private:
    std::string post, phone, responsibility;

public:
    std::string get_string() override;
};

