#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World\n";
}


string toString(Student *student) {
        string csvString = "\"" + student->name + "\", \"" + student->usf_id + "\", \"" + student->email + "\", \"" + to_string(student->grade_presentation) + "\", \"" + to_string(student->grade_essay1) + "\", \"" + to_string(student->grade_essay2) + "\", \"" + to_string(student->grade_termProject) + "\"";

        //string stringTesting = "Student Name: " + student->name + "," + "USF ID: " + student->usfID+ "," + "Email: " + student->email + "," + "Grade of presentation: " + student->gradeOfPresentation + "," + "Grade of Essay No. 1: " + student->gradeOfEssay1 + "," + "Grade of Essay No. 2: " + student->gradeOfEssay2 + "," + "Grade of the term project: " + student->gradeofTermProject;
        return(csvString);
}
