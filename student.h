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
		string name;
		string usfId;
		string email;
		double gradePresentation;
		double gradeEssay1;
		double gradeEssay2;
		double gradeTermProject;
		
		bool promptToChange(string fieldName);
		void getInput(bool isNew);
		
	public:
		Student();
		Student(string _name, string _usfId, string _email, double _gradePresentation, double _gradeEssay1, double _gradeEssay2, double _gradeTermProject);
		Student(string line);
		
		bool search(string keyword);
		void getInput();
		
		string toString();
		void print();
		
		string getName();
		void setName(string _name);
		
		string getUsfId();
		void setUsfId(string _usfId);
		
		string getEmail();
		void setEmail(string _email);
		
		double getGradePresentation();
		void setGradePresentation(double _gradePresentation);
		
		double getGradeEssay1();
		void setGradeEssay1(double _gradeEssay1);
		
		double getGradeEssay2();
		void setGradeEssay2(double _gradeEssay2);
		
		double getGradeTermProject();
		void setGradeTermProject(double _gradeTermProject);

};
#endif
