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

string Student::toString(Student *student) {

        string replace = "\"\"";

        for (int i = 0; i < student->name.length(); i++)
        {
                if (student->name[i] == '"')
                {
                        student->name.replace(i, 1, replace);
                        i += 2;
                }
        }

        for (int i = 0; i < student->usf_id.length(); i++)
        {
                if (student->usf_id[i] == '"')
                {
                        student->usf_id.replace(i, 1, replace);
                        i += 2;
                }
        }

        for (int i = 0; i < student->email.length(); i++)
        {
                if (student->email[i] == '"')
                {
                        student->email.replace(i, 1, replace);
                        i += 2;
                }
        }

        string csvString = "\"" + student->name + "\", \"" + student->usf_id + "\", \"" + student->email + "\", \"" + to_string(student->grade_presentation) + "\", \"" + to_string(student->grade_essay1) + "\", \"" + to_string(student->grade_essay2) + "\", \"" + to_string(student->grade_termProject) + "\"";

        //string stringTesting = "Student Name: " + student->name + "," + "USF ID: " + student->usfID+ "," + "Email: " + student->email + "," + "Grade of presentation: " + student->gradeOfPresentation + "," + "Grade of Essay No. 1: " + student->gradeOfEssay1 + "," + "Grade of Essay No. 2: " + student->gradeOfEssay2 + "," + "Grade of the term project: " + student->gradeofTermProject;
        return(csvString);
}

Student::~Student()
{
}
