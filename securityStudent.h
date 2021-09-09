#pragma once
#include <string>
#include "degree.h"
#include "student.h"



class SecurityStudent : public Student //security is type of student
{
public:
	SecurityStudent();
	SecurityStudent(std::string ID, std::string firstN, std::string lastN, std::string email, std::string ageNum, int* numDays[], Degree type);


	Degree getDegreeProgram();
	void setDegreeProgram(Degree b);
	void print();

	~SecurityStudent();

};