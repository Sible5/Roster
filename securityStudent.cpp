#include <iostream>
#include "securityStudent.h"

SecurityStudent::SecurityStudent()
{
	setDegreeProgram(SECURITY);
}

SecurityStudent::SecurityStudent(std::string ID, std::string firstN, std::string lastN, std::string email, std::string ageNum, int* numDays[],Degree type)
{
	setDegreeProgram(SECURITY);
}

Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY; 
}

void SecurityStudent::setDegreeProgram(Degree b)
{
	this->dtype = SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	std::cout << "SECURITY" << std::endl;
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}