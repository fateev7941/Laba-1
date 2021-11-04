#include "University.h"

University::University(std::string FIO) : 
	FIO(FIO) {
	std::cout << "University(FIO)\n";
}

University::~University()
{
	std::cout << "~University()\n";
}
