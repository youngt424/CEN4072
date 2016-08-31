#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Hello World\n";
}


string toString(Student *student) {

        string replaceComma = "\"\"";

        // Check Student name for commas
        for (int i = 0; i < student->name.length(); i++)
        {
                if (student->name[i] == '"')
                {
                        student->name.replace(i, 1, replaceComma);
                        i += 2;
                }
        }

        // Check Student ID for commas
        for (int i = 0; i < student->usfID.length(); i++)
        {
                if (student->usfID[i] == '"')
                {
                        student->usfID.replace(i, 1, replaceComma);
                        i += 2;
                }
        }

        // Check Student email for commas
        for (int i = 0; i < student->email.length(); i++)
        {
                if (student->email[i] == '"')
                {
                        student->email.replace(i, 1, replaceComma);
                        i += 2;
                }
        }

        string csvString = "\"" + student->name + "\", \"" + student->usfID + "\", \"" + student->email + "\", \"" + to_string(student->gradeOfPresentation) + "\", \"" + to_string(student->gradeOfEssay1) + "\", \"" + to_string(student->gradeOfEssay2) + "\", \"" + to_string(student->gradeofTermProject) + "\"";

        //string stringTesting = "Student Name: " + student->name + "," + "USF ID: " + student->usfID+ "," + "Email: " + student->email + "," + "Grade of presentation: " + student->gradeOfPresentation + "," + "Grade of Essay No. 1: " + student->gradeOfEssay1 + "," + "Grade of Essay No. 2: " + student->gradeOfEssay2 + "," + "Grade of the term project: " + student->gradeofTermProject;
        return(csvString);
}
