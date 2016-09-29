#ifndef STUDENT_H
#define STUDENT_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Student
{
	private:
		//Field names
		string name;
		string usfId;
		string email;
		double gradePresentation;
		double gradeEssay1;
		double gradeEssay2;
		double gradeTermProject;
		
		/*
		Precondition: an input string to specifiy a field to update
		Postcondition: returns true if the user specifies they wish to update the field
		*/
		bool promptToChange(string fieldName);
		
		/*
		Precondition: None
		Postcondition: Prompts user to change each field
		*/
		void getInput(bool isNew);
		
	public:
		Student();
		Student(string _name, string _usfId, string _email, double _gradePresentation, double _gradeEssay1, double _gradeEssay2, double _gradeTermProject);
		Student(string line);
		
		/*
		Precondition: an input string as a keyword to search for
		Postcondition: returns true if the keyword matches any fields
		*/
		bool search(string keyword);
		
		/*
		Precondition: None
		Postcondition: Prompts user to change each field
		*/
		void getInput();
		
		/*
		Precondition: None
		Postcondition: returns a string containing student information in the
						form "name, usfId, email, gradePresentation, gradeEssay1,
						gradeEssay2, gradeTermProject"
		*/
		string toString();
		
		/*
		Precondition: None
		Postcondition: Prints student information to console
		*/
		void print();
		
		/*
		Precondition: None
		Postcondition: returns student name
		*/
		string getName();
		
		/*
		Precondition: an input string
		Postcondition: sets student name to the input string
		*/
		void setName(string _name);
		
		/*
		Precondition: None
		Postcondition: returns student usfId
		*/
		string getUsfId();
		
		/*
		Precondition: an input string
		Postcondition: sets student usfId to the input string
		*/
		void setUsfId(string _usfId);
		
		/*
		Precondition: None
		Postcondition: returns student email
		*/
		string getEmail();
		
		/*
		Precondition: an input string
		Postcondition: sets student usfId to the input string
		*/
		void setEmail(string _email);
		
		/*
		Precondition: None
		Postcondition: returns student presentation grade
		*/
		double getGradePresentation();
		
		/*
		Precondition: an input number
		Postcondition: sets student presentation grade to input number
		*/
		void setGradePresentation(double _gradePresentation);
		
		/*
		Precondition: None
		Postcondition: returns student essay 1 grade
		*/
		double getGradeEssay1();
		
		/*
		Precondition: an input number
		Postcondition: sets student essay 1 grade to input number
		*/
		void setGradeEssay1(double _gradeEssay1);
		
		/*
		Precondition: None
		Postcondition: returns student essay 2 grade
		*/
		double getGradeEssay2();
		
		/*
		Precondition: an input number
		Postcondition: sets student essay 2 grade to input number
		*/
		void setGradeEssay2(double _gradeEssay2);
		
		/*
		Precondition: None
		Postcondition: returns student term project grade
		*/
		double getGradeTermProject();
		
		/*
		Precondition: an input number
		Postcondition: sets student term project grade to input number
		*/
		void setGradeTermProject(double _gradeTermProject);

};
#endif
