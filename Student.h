#ifndef STUDENT_H
#define STUDENT_H
#include<vector>
#include<string>
#include <cstdlib>
#include<iostream>
#include<sstream>
#include<stdlib.h>
using namespace std;

class Student
{
public:

	Student();
	Student(string nm, string id, string emal, double g_presentation, double g_essay1, double g_essay2, double g_termProject);
	Student(vector<string> stu_info);
	string toString();
	~Student();
private:
	string name;
	string usf_id;
	string email;
	double grade_presentation;
	double grade_essay1;
	double grade_essay2;
	double grade_termProject;

};

#endif 