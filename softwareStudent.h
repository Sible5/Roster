#pragma once
#include <string>
#include "degree.h"
#include "student.h"



class SoftwareStudent : public Student //software is type of student
{
public:
	SoftwareStudent();
	SoftwareStudent(std::string ID, std::string firstN, std::string lastN, std::string email, std::string ageNum, int* numDays[], Degree type);


	Degree getDegreeProgram();
	void setDegreeProgram(Degree b);
	void print();

	~SoftwareStudent();

};