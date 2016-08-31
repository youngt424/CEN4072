#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student
{
public:
	Student();
	string name;
	string usf_id;
	string email;
	double grade_presentation;
	double grade_essay1;
	double grade_essay2;
	double grade_termProject;
	~Student();
};

#endif 

