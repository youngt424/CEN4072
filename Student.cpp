#include "Student.h"

Student::Student()
{
	name="";
	usf_id="";
	email="";
	grade_presentation=0;
	grade_essay1=0;
	grade_essay2=0;
	grade_termProject=0;
}

Student::Student(string nm, string id, string emal, double g_presentation, double g_essay1, double g_essay2, double g_termProject)
{
	name = nm;
	usf_id  = id;
	email = emal;
	grade_presentation = g_presentation;
    	grade_essay1 = g_essay1;
	grade_essay2 = g_essay2;
	grade_termProject = g_termProject;
}

Student::~Student()
{
}
