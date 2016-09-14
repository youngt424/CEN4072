#include "Student.h"
#include<string>

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

Student::Student(vector<string> stu_info)
{
	for(int i=0; i<stu_info.size(); i++){
		switch(i) {
			case 0:
				name = stu_info.at(i);
				break;
			case 1:
				usf_id = stu_info.at(i);
				break;
			case 2:
				email = stu_info.at(i);
				break;
			case 3:
				grade_presentation = stod(stu_info.at(i));
				break;
			case 4:
				grade_essay1 = stod(stu_info.at(i));
				break;
			case 5:
				grade_essay2 = stod(stu_info.at(i));
				break;
			case 6:
				grade_termProject = stod(stu_info.at(i));
				break;
			default:
				break;
		}
	}
}

Student::~Student()
{
}
