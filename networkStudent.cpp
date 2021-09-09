#include <iostream>
#include "networkStudent.h"

NetworkStudent::NetworkStudent()
{
	setDegreeProgram(NETWORKING);
}

NetworkStudent::NetworkStudent(std::string ID, std::string firstN, std::string lastN, std::string email, std::string ageNum, int* numDays[], Degree type)
{
	setDegreeProgram(NETWORKING);
}

Degree NetworkStudent::getDegreeProgram()
{
	return NETWORKING;
}

void NetworkStudent::setDegreeProgram(Degree b)
{
	this->dtype = NETWORKING;
}

void NetworkStudent::print()
{
	this->Student::print();
	std::cout << "NETWORKING" << std::endl;
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}