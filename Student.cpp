#include "Student.h"

Student::Student()
{
	name = "";
	usf_id = "";
	email = "";
	grade_presentation = 0;
	grade_essay1 = 0;
	grade_essay2 = 0;
	grade_termProject = 0;
}

Student::Student(string nm, string id, string emal, double g_presentation, double g_essay1, double g_essay2, double g_termProject)
{
	name = nm;
	usf_id = id;
	email = emal;
	grade_presentation = g_presentation;
	grade_essay1 = g_essay1;
	grade_essay2 = g_essay2;
	grade_termProject = g_termProject;
}

Student::Student(vector<string> stu_info)
{
	for (int i = 0; i<stu_info.size(); i++){
		switch (i) {
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
			grade_presentation = atof(stu_info.at(i).c_str());
			break;
		case 4:
			grade_essay1 = atof(stu_info.at(i).c_str());
			break;
		case 5:
			grade_essay2 = atof(stu_info.at(i).c_str());
			break;
		case 6:
			grade_termProject = atof(stu_info.at(i).c_str());
			break;
		default:
			break;
		}
	}
}

string Student::toString() {

	string replace = "\"\"";

	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == '"')
		{
			name.replace(i, 1, replace);
			i += 2;
		}
	}

	for (int i = 0; i < usf_id.length(); i++)
	{
		if (usf_id[i] == '"')
		{
			usf_id.replace(i, 1, replace);
			i += 2;
		}
	}

	for (int i = 0; i < email.length(); i++)
	{
		if (email[i] == '"')
		{
			email.replace(i, 1, replace);
			i += 2;
		}
	}
	
	stringstream buffer;
	buffer << grade_presentation;
	string str_gp = buffer.str();
	buffer.str("");
	
	buffer << grade_essay1;
	string str_e1 = buffer.str();
	buffer.str("");
	
	buffer << grade_essay2;
	string str_e2 = buffer.str();
	buffer.str("");
	
	buffer << grade_termProject;
	string str_tp = buffer.str();
	buffer.str("");

	string csvString = "\"" + name + "\", \"" + usf_id + "\", \"" + email + "\", \"" + str_gp + "\", \"" + str_e1 + "\", \"" + str_e2 + "\", \"" + str_tp + "\"";

	return(csvString);
}

Student::~Student()
{
}