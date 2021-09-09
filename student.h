#pragma once
#include <string>
#include "degree.h"
using std::string;

class Student //class for student
{

	public:

		const static int daysArraySize = 3;



	protected:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string emailAddr;
		std::string age;
		int* numDays;
		Degree dtype;


	public:


		Student(); // empty constructor

		Student(std::string ID, std::string firstN, std::string lastN, std::string email,std::string ageNum, int numDays[]);
		//getters
		std::string getID();
		std::string getFirst();
		std::string getLast();
		std::string getEmail();
		std::string getAge();
		int* getNumDays();
		virtual Degree getDegreeProgram() = 0; //only for sub classes

		//setters

		void setID(std::string ID);
		void setFirst(std::string firstN);
		void setLast(std::string lastN);
		void setEmail(std::string email);
		void setAge(std::string ageNum);
		void setDays(int numDays[]);
		//virtual void setDegreeType(Degree b) = 0;

		virtual void print();

		~Student();

		};