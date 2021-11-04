#pragma once
#include <string>
#include "University.h"
class AdministrativeStaff :
    public University
{
private:
    std::string post, phone, responsibility;

public:
    AdministrativeStaff(std::string FIO, std::string post, std::string phone, std::string responsibility);
    ~AdministrativeStaff();
    std::string get_string() override;
    std::string get_string_data() override;
};
