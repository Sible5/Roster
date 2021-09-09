#pragma once
#include <string>
#include <iostream>
#include "student.h"

const int numStudents = 5;

//only 5 students
string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Alex,Sible,asible@wgu.edu,24,31,55,36,SOFTWARE"
};


//roster stores all the students
class Roster {
public:
	int lastIndex;//index of last student
	int totalCapacity;//The maximum size of the roster
	Student** classRosterArray;//array of pointers holding data above
	Roster();//empty constructor 
	Roster(int totalCapacity);//this constructor does same as above, but sets max size
	void parse(std::string row);
	void add(std::string studentID,std::string firstName, std::string lastName, std::string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree type);//creates the objects, and adds them
	void print_All();//prints all books in repository using each book's print() method
	bool remove(std::string studentID);//removes a book
	void printDaysInCourse(std::string studentID);//Prints days in course for student
	void printInvalidEmails();//Locates and prints emails that are wrong
	void printByDegreeProgram(Degree degreeProgram);//Prints all students each degree
	~Roster();//Destructor
};

int main();
