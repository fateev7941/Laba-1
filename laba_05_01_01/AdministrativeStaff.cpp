#include "AdministrativeStaff.h"

AdministrativeStaff::AdministrativeStaff(std::string FIO, std::string post, std::string phone, std::string responsibility) :
    University(FIO), post(post), phone(phone), responsibility(responsibility) {
    std::cout << "AdministrativeStaff(FIO, post, phone, responsibility)\n";
}

AdministrativeStaff::~AdministrativeStaff()
{
    std::cout << "~AdministrativeStaff()\n";
}

std::string AdministrativeStaff::get_string()
{
	return "Административный персонал: \n\tФИО: " + FIO +
		"\n\tдолжность: " + post +
		"\n\tтелефон: " + phone +
		"\n\tобласть ответственности: " + responsibility + "\n";
}

std::string AdministrativeStaff::get_string_data()
{
	return "AdministrativeStaff\n" +
		FIO + "\n" +
		post + "\n" +
		phone + "\n" +
		responsibility + "\n";
}
