#include <iostream>
#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent()
{
	setDegreeProgram(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(std::string ID, std::string firstN, std::string lastN, std::string email, std::string ageNum, int* numDays[], Degree type)
{
	setDegreeProgram(SOFTWARE);
}

Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

void SoftwareStudent::setDegreeProgram(Degree b)
{
	this->dtype = SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	std::cout << "SOFTWARE" << std::endl;
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}