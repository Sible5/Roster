#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>


Student::Student() //empty constructor
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddr = "";
	this->age = "";
	this->numDays = new int [daysArraySize];
	for (int i = 0; i < daysArraySize; i++) this->numDays[i] = 0;

	//no type here
}
Student::Student(std::string ID, std::string firstN, std::string lastN, 
	std::string email, std::string ageNum, int numDays[])
{
	this->studentID = ID;
	this->firstName = firstN;
	this->lastName = lastN;
	this->emailAddr = email;
	this->age = ageNum;
	this->numDays = new int [daysArraySize];
	for (int i = 0; i < daysArraySize; i++) this->numDays[i] = numDays[i];
	

}

//getters

std::string Student::getID()
{
	return studentID;
}

std::string Student::getFirst()
{
	return firstName;
}
std::string Student::getLast()
{
	return lastName;
}
std::string Student::getEmail()
{
	return emailAddr;
}
std::string Student::getAge()
{
	return age;
}
int* Student::getNumDays()
{
	return numDays;
}
//setters!
void Student::setID(std::string ID)
{
	studentID = ID;
}

void Student::setFirst(std::string firstN)
{
	firstName = firstN;
}
void Student::setLast(std::string lastN)
{
	lastName = lastN;
}
void Student::setEmail(std::string email)
{
	emailAddr = email;
}
void Student::setAge(std::string ageNum)
{
	int age = std::stoi(ageNum);
}
void Student::setDays(int numDays[])
{
	for (int i = 0; i < 3; i++)
		this->numDays[i] = numDays[i];

}

void Student::print()
{//show labels *data* tab label
	std::cout << studentID << "\t";
	std::cout << firstName << "\t";
	std::cout << lastName << "\t";
	std::cout << emailAddr << "\t";
	std::cout << age << "\t";
	std::cout << numDays[0] << "\t";
	std::cout << numDays[1] << "\t";
	std::cout << numDays[2] << "\t";

}
 //Degree getDegreeProgram()


Student::~Student()
{}
