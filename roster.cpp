#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "degree.h"
#include <string>
#include <iostream>
#include <cstring>




Roster::Roster()
{
	this->totalCapacity = 0;
	this->lastIndex = -1; //empty
	this->classRosterArray = nullptr;
}

Roster::Roster(int totalCapacity)//total size
{
	this->totalCapacity = totalCapacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [totalCapacity];
}

void Roster::parse(std::string row)
{
	//Roster classRoster;
	if (lastIndex < 5) {
	//type checking at end, because important degree bit is at the end
	
	//begin parsing on commas
		//read student ID (A1-5)
		lastIndex++;

		int rightHand = studentData[lastIndex].find(",");

		std::string tempID = studentData[lastIndex].substr(0, rightHand); //ID as string to pass to add function

		int leftHand = rightHand + 1;

		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempFirst = studentData[lastIndex].substr(leftHand, rightHand - leftHand);//first name as string to function

		leftHand = rightHand + 1;
		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempLast = studentData[lastIndex].substr(leftHand, rightHand - leftHand); //last name as string for function

		leftHand = rightHand + 1;
		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempEmail = studentData[lastIndex].substr(leftHand, rightHand - leftHand); //email as string

		leftHand = rightHand + 1;
		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempAgeStr = studentData[lastIndex].substr(leftHand, rightHand - leftHand); //age as string
	
		//int tempAgeInt = std::stoi(tempAgeStr,nullptr,10); //age as int - what actually needs to be passed through

		leftHand = rightHand + 1;
		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempDayOneStr = studentData[lastIndex].substr(leftHand, rightHand - leftHand); // day one as String

		int tempDayOneInt = std::stoi(tempDayOneStr); //Day1 as int - what actually needs to be passed through

		leftHand = rightHand + 1;
		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempDayTwoStr = studentData[lastIndex].substr(leftHand, rightHand - leftHand); // day one as String

		int tempDayTwoInt = std::stoi(tempDayTwoStr); //Day1 as int - what actually needs to be passed through

		leftHand = rightHand + 1;
		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempDayThreeStr = studentData[lastIndex].substr(leftHand, rightHand - leftHand); // day e as String

		int tempDayThreeInt = std::stoi(tempDayThreeStr); //Day1 as int - what actually needs to be passed through

		leftHand = rightHand + 1;
		rightHand = studentData[lastIndex].find(",", leftHand);

		std::string tempType = studentData[lastIndex].substr(leftHand, rightHand - leftHand);

		Degree type = SOFTWARE;
		if (tempType == "SECURITY") {//setting degree types here.
			type = SECURITY;

			
		}
		else if (tempType == "NETWORKING") {
			type = NETWORKING;
			
		}
		else if (tempType == "SOFTWARE") {
			type = SOFTWARE;
			
		}
		int tempAgeInt = 0;
	

		add(tempID, tempFirst, tempLast, tempEmail, tempAgeInt, tempDayOneInt, tempDayTwoInt, tempDayThreeInt, type);
	}
	



	
}
void Roster::printInvalidEmails() {
	std::cout << "Here are the invalid email addresses" << std::endl;
	for (int i = 0; i <= lastIndex; i++) {
		std::string tempEmail = classRosterArray[i]->getEmail();
		if (tempEmail.find(" ") != string::npos) {
			std::cout << "Invalid Email: " ;
			std::cout << tempEmail << std::endl;
		}
		if (tempEmail.find("@") == string::npos) {
			std::cout << "Invalid Email: " ;
			std::cout << tempEmail << std::endl;
		}
		if (tempEmail.find(".") == string::npos) {
			std::cout << "Invalid Email: ";
			std::cout << tempEmail << std::endl;
		}
		
	}
	
}

void Roster::printDaysInCourse(std::string studentID) {
	for (int i = 0; i <= lastIndex; i++) {
		int* p = classRosterArray[i]->getNumDays();
		if (studentID == classRosterArray[i]->getID()) {
			std::cout << "The average number of days in a course for " << studentID << " : " << (p[0] + p[1] + p[2]) / 3 << " days." << std::endl;
		}
	}
	
	
}

void Roster::printByDegreeProgram(Degree degree) {

	std::cout << "Here are the students in the Software program." << std::endl;
	for (int i = 0; i <= lastIndex; i++) {
		if (degree == classRosterArray[i]->getDegreeProgram()) {
			classRosterArray[i]->print();
		}
	}
}

bool Roster::remove(std::string studentID) {

	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr) {

			if (studentID == classRosterArray[i]->getID()) {
				classRosterArray[i] = nullptr;
				return true;
			}
		}

	}
	return false;
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, 
	int daysInCourse1, int daysInCourse2, int daysInCourse3,Degree type)
{
	Degree typeSec = SECURITY;
	Degree typeNet = NETWORKING;
	Degree typeSof = SOFTWARE;
	int tempDayArray[Student::daysArraySize];

	tempDayArray[0] = daysInCourse1;
	tempDayArray[1] = daysInCourse2;
	tempDayArray[2] = daysInCourse3;
	////classRoster[lastIndex]->setDegreeProgram(SECURITY)
	if (type == typeSec) {
		classRosterArray[lastIndex] = new SecurityStudent();
		//classRosterArray[lastIndex]->setDegreeType(SECURITY);
	}
	else if (type == typeNet) {
		//classRosterArray[lastIndex]->setDegreeType(NETWORKING);
		classRosterArray[lastIndex] = new NetworkStudent();
		
	}
	else if (type == typeSof) 
		{
		classRosterArray[lastIndex] = new SoftwareStudent();
			//classRosterArray[lastIndex]->setDegreeType(SOFTWARE);=
	}

	std::string AgeTemp = std::to_string(age);
	classRosterArray[lastIndex]->setID(studentID);
	classRosterArray[lastIndex]->setFirst(firstName);
	classRosterArray[lastIndex]->setLast(lastName);
	classRosterArray[lastIndex]->setEmail(emailAddress);
	classRosterArray[lastIndex]->setAge(AgeTemp);
	classRosterArray[lastIndex]->setDays(tempDayArray);
}

void Roster::print_All()
{
	for (int i=0; i <= this->lastIndex; i++)
	{
		(this->classRosterArray)[i]->print();
	}
	std::cout << std::endl;
}


Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		delete this->classRosterArray[i];

	}
	delete this;
}

int main(){
	std::cout << "Course: Scripting and Programming Applications - C867 \t wrote using C++ \t Student ID: #000972826 \t by Alex Sible" << std::endl;

	Roster* classRosterArray = new Roster(5);

	classRosterArray->parse(studentData[0]);
	classRosterArray->parse(studentData[1]);
	classRosterArray->parse(studentData[2]);
	classRosterArray->parse(studentData[3]);
	classRosterArray->parse(studentData[4]);

	classRosterArray->print_All();
	classRosterArray->printInvalidEmails();
	classRosterArray->printDaysInCourse("A1");
	classRosterArray->printDaysInCourse("A2");
	classRosterArray->printDaysInCourse("A3");
	classRosterArray->printDaysInCourse("A4");
	classRosterArray->printDaysInCourse("A5");
	classRosterArray->printByDegreeProgram(SOFTWARE);
	if (!classRosterArray->remove("A3")) {
		std::cout << "Student not found." << std::endl;
	}
	if (!classRosterArray->remove("A3")) {
		std::cout << "Student not found." << std::endl;
	}


	return 0;
}


