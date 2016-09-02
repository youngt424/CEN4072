#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student
{
public:
	
	Student();
	Student(string nm, string id, string emal, double g_presentaion, double g_essay1, double g_essay2, double g_termProject);
	~Student();
	
	string name;
	string usf_id;
	string email;
	double grade_presentation;
	double grade_essay1;
	double grade_essay2;
	double grade_termProject;
	
};

#endif 

