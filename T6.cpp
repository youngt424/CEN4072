//ClassInterface() is the interface you should use to test in the terminal,
//In order to not automatically start the manual interface you can call ClassInterface(bool)
//The value of the bool does not matter but you can use this to run automated tests

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

enum class Fields { name, Id, email, presentation, essay1, essay2, termProject };


int commaScan(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') return -1;
	}
	return 0;
}

//variables used to hold student information
class Student {
public:
	string name;
	string usfId;
	string email;
	int presentation;
	int essay1;
	int essay2;
	int termProject;
};

//class including names of all functions
class ClassInterface {

	vector<Student> classList;
public:
	ClassInterface(); // for user interraction
	ClassInterface(bool); // for automation
	~ClassInterface();

	int addStudent(string, string, string, int, int, int, int);
	int deleteStudent(int);

	int getByName(string);
	int getById(string);
	int getByEmail(string);

	void printStudent(int);

	int updateField(int, Fields, string);

	void mainInterface();
	void addStudentInterface();
	void deleteStudentInterface();
	void searchStudentInterface();
	void updateFieldsInterface();
	bool uploadFile(const string&);

	void writeFile();
};

int main() {

	ClassInterface myClass;

	return 0;
}

//constructor
ClassInterface::ClassInterface() {

	mainInterface();
}

//constructor
ClassInterface::ClassInterface(bool automated) {

}

//destructor
ClassInterface::~ClassInterface() {

}

//function for adding a student including checks for proper input
int ClassInterface::addStudent(string name, string usfId, string email, int presentation, int essay1, int essay2, int termProject) {
	Student student;
	bool isFine = true;

	if (name.length() < 1) {
		cout << "Name too short." << endl;
		isFine = false;
	}
	if (commaScan(name) == -1) {
		cout << "Entry cannot have a comma." << endl;
		isFine = false;
	}
	if (name.length() > 40) {
		cout << "Name too long." << endl;
		isFine = false;
	}

	if (usfId.length() < 1) {
		cout << "Id too short." << endl;
		isFine = false;
	}
	if (usfId.length() > 10) {
		cout << "Id too long." << endl;
		isFine = false;
	}
	if (commaScan(usfId) == -1) {
		cout << "Entry cannot have a comma." << endl;
		isFine = false;
	}
	if (email.length() < 5) {
		cout << "Email is invalid." << endl;
		isFine = false;
	}
	if (email.length() > 40) {
		cout << "Email too long." << endl;
		isFine = false;
	}
	if (commaScan(email) == -1) {
		cout << "Entry cannot have a comma." << endl;
		isFine = false;
	}
	bool validEmail = false;
	for (int i = 1; i < email.length() - 3; i++) {
		if (email[i] == '@') {
			for (int j = i + 2; j < email.length() - 1; j++) {
				if (email[j] == '.') validEmail = true;
			}
		}
	}
	if (validEmail == false) {
		cout << "Email format is invalid." << endl;
		isFine = false;
	}
	if (presentation > 4 || presentation < 0) {
		cout << "Presentation's value isn't in the range 0 - 4." << endl;
		isFine = false;
	}
	if (essay1 > 4 || essay1 < 0) {
		cout << "First essay's value isn't in the range 0 - 4." << endl;
		isFine = false;
	}
	if (essay2 > 4 || essay2 < 0) {
		cout << "Second essay's value isn't in the range 0 - 4." << endl;
		isFine = false;
	}
	if (termProject > 4 || termProject < 0) {
		cout << "Term Project's value isn't in the range 0 - 4." << endl;
		isFine = false;
	}

	if (!isFine) {
		cout << "There are errors with the inputs." << endl;
		return -1;
	}

	if (isFine) {
		student.name = name;
		student.usfId = usfId;
		student.email = email;
		student.presentation = presentation;
		student.essay1 = essay1;
		student.essay2 = essay2;
		student.termProject = termProject;

		classList.push_back(student);
	}

	return 0;
}

//function to delete a student
int ClassInterface::deleteStudent(int index) {
	if (index >= classList.size()) {
		cout << "Index out of range." << endl;
		return -1;
	}

	classList.erase(classList.begin() + index);

	return 0;
}

//function to find student by name
int ClassInterface::getByName(string name) {
	for (int i = 0; i < classList.size(); i++) {
		if (name == classList[i].name) return i;
	}
	cout << "Student not found." << endl;
	return -1;
}

//function to find student by ID
int ClassInterface::getById(string Id) {
	for (int i = 0; i < classList.size(); i++) {
		if (Id == classList[i].usfId) return i;
	}

	cout << "Student not found." << endl;
	return -1;
}

//function for finding a student by email
int ClassInterface::getByEmail(string email) {
	for (int i = 0; i < classList.size(); i++) {
		if (email == classList[i].email) return i;
	}

	cout << "Student not found." << endl;
	return -1;
}

//The main interface for printing a students information
void ClassInterface::printStudent(int index) {
	if (index >= classList.size() || index < 0) {
		cout << "Out of range" << endl;
		return;
	}
	cout << endl
		<< "Name: " << classList[index].name << endl
		<< "UsfId: " << classList[index].usfId << endl
		<< "Email: " << classList[index].email << endl
		<< "Presentation: " << classList[index].presentation << endl
		<< "Essay 1: " << classList[index].essay1 << endl
		<< "Essay 2: " << classList[index].essay2 << endl
		<< "Term Project: " << classList[index].termProject << endl;
}

//function for updating a students grade
int ClassInterface::updateField(int index, Fields field, string value)
{
	int valueInt;

	if (index >= classList.size()) {
		cout << "Index out of range." << endl;
		return -1;
	}
	if (field == Fields::essay1 || field == Fields::essay2 || field == Fields::presentation || field == Fields::termProject) {
		valueInt = stoi(value);

		if (valueInt > 4 || valueInt < 0) {
			cout << "Grades must be in the range 0-4 inclusive." << endl;
			return -1;
		}
		if (field == Fields::essay1) classList[index].essay1 = valueInt;
		if (field == Fields::essay2) classList[index].essay2 = valueInt;
		if (field == Fields::presentation) classList[index].presentation = valueInt;
		if (field == Fields::termProject) classList[index].termProject = valueInt;
	}

	if (field == Fields::name) {
		if (value.length() > 40) {
			cout << "Name too long." << endl;
			return -1;
		}
		if (value.length() < 1) {
			cout << "Name too short." << endl;
			return -1;
		}
		if (commaScan(value) == -1) {
			cout << "Entry cannot have a comma." << endl;
			return -1;
		}
		classList[index].name = value;
	}
	if (field == Fields::Id) {
		if (value.length() > 10) {
			cout << "Id too long." << endl;
			return -1;
		}
		if (value.length() < 1) {
			cout << "Id too short." << endl;
			return -1;
		}
		if (commaScan(value) == -1) {
			cout << "Entry cannot have a comma." << endl;
			return -1;
		}
		classList[index].usfId = value;
	}
	if (field == Fields::email) {
		if (value.length() > 40) {
			cout << "Email too long." << endl;
			return -1;
		}
		if (value.length() < 5) {
			cout << "Email too short." << endl;
			return -1;
		}
		if (commaScan(value) == -1) {
			cout << "Entry cannot have a comma." << endl;
			return -1;
		}
		bool validEmail = false;
		for (int i = 1; i < value.length() - 3; i++) {
			if (value[i] == '@') {
				for (int j = i + 2; j < value.length() - 1; j++) {
					if (value[j] == '.') validEmail = true;
				}
			}
		}
		if (validEmail == false) {
			cout << "Email format is invalid." << endl;
			return -1;
		}
		classList[index].email = value;
	}

	return 0;
}

//this is the main interface that loads when you run the program
void ClassInterface::mainInterface() {
	uploadFile("classInfo.txt");
	cout << "Welome to the Class interface," << endl
		<< "-------------------------------" << endl;

	bool done = false;
	while (!done) {
		string option;
		cout << "Please select one of the following" << endl
			<< "by typing in it's respective integer" << endl << endl;
		cout << "1. Add Student" << endl
			<< "2. Remove Student" << endl
			<< "3. Search for Student" << endl
			<< "4. Edit a Record" << endl
			<< "5. Quit" << endl;
		getline(cin, option);
		if (option == "1") addStudentInterface();
		else if (option == "2") deleteStudentInterface();
		else if (option == "3") searchStudentInterface();
		else if (option == "4") updateFieldsInterface();
		else if (option == "5") done = true;
		else {
			cout << "That was an invalid option. Pick again." << endl;
		}
	}
	writeFile();
}

//function to add a new student
void ClassInterface::addStudentInterface() {
	string name = "";
	string id = "";
	string email = "";
	int presentation;
	string presentationString;
	int essay1;
	string essay1String;
	int essay2;
	string essay2String;
	int termProject;
	string termProjectSting;
	bool good = false;

	//adding new students and checks for correct inputs
	while (true) {
		cout << "Please insert the name of the student," << endl
			<< "up to 40 characters." << endl;
		getline(cin, name);
		if (name.length() > 40) {
			cout << "That name is too long." << endl;
			continue;
		}
		if (name.length() == 0) {
			cout << "That name contained no text." << endl;
			continue;
		}
		if (commaScan(name) == -1) {
			cout << "Entry cannot have a comma." << endl;
			continue;
		}
		break;
	}

	while (true) {
		cout << "Please insert the student's Unumber." << endl;
		getline(cin, id);
		if (id.length() > 10) {
			cout << "That ID is too long." << endl;
			continue;
		}
		if (id.length() == 0) {
			cout << "That ID is too short." << endl;
			continue;
		}
		if (commaScan(id) == -1) {
			cout << "Entry cannot have a comma." << endl;
			continue;
		}
		break;

	}
	while (true) {
		cout << "Please insert the student's email." << endl;
		getline(cin, email);
		if (email.length() > 40) {
			cout << "That email is too long." << endl;
			continue;
		}
		if (email.length() == 0) {
			cout << "That email is too short." << endl;
			continue;
		}
		if (commaScan(email) == -1) {
			cout << "Entry cannot have a comma." << endl;
			continue;
		}
		bool validEmail = false;
		for (int i = 1; i < email.length() - 3; i++) {
			if (email[i] == '@') {
				for (int j = i + 2; j < email.length() - 1; j++) {
					if (email[j] == '.') validEmail = true;
				}
			}
		}
		if (validEmail == false) {
			cout << "Email format is invalid." << endl;
			continue;
		}
		break;
	}
	//Entering the grades for new student
	while (true) {
		cout << "Please insert the student's grade for their presentation." << endl;
		getline(cin, presentationString);
		presentation = stoi(presentationString);
		if (presentation > 4 || presentation < 0) {
			cout << "That is an invalid number." << endl;
			continue;
		}
		break;
	}
	while (true) {
		cout << "Please insert the student's grade for their first essay." << endl;
		getline(cin, essay1String);
		essay1 = stoi(essay1String);
		if (essay1 > 4 || essay1 < 0) {
			cout << "That is an invalid number." << endl;
			continue;
		}
		break;
	}
	while (true) {
		cout << "Please insert the student's grade for their second essay." << endl;
		getline(cin, essay2String);
		essay2 = stoi(essay2String);
		if (essay2 > 4 || essay2 < 0) {
			cout << "That is an invalid number." << endl;
			continue;
		}
		break;
	}
	while (true) {
		cout << "Please insert the student's grade for their term project." << endl;
		getline(cin, termProjectSting);
		termProject = stoi(termProjectSting);
		if (termProject > 4 || termProject < 0) {
			cout << "That is an invalid number." << endl;
			continue;
		}
		break;
	}
	addStudent(name, id, email, presentation, essay1, essay2, termProject);
}

//function to remove a studen
void ClassInterface::deleteStudentInterface() {
	string input;
	string value;

	int index;

	while (true) {
		cout << "How would you like to identify the student to delete?" << endl
			<< "1. Name" << endl
			<< "2. UsfId" << endl
			<< "3. Email" << endl
			<< "4. Back" << endl;
		getline(cin, input);
		if (input == "1") {
			cout << "Please enter the student's name." << endl;
			getline(cin, value);
			index = getByName(value);
			if (index == -1) continue;
		}
		else if (input == "2") {
			cout << "Please enter the student's UsfId." << endl;
			getline(cin, value);
			index = getById(value);
			if (index == -1) continue;
		}
		else if (input == "3") {
			cout << "Please enter the student's email." << endl;
			getline(cin, value);
			index = getByEmail(value);
			if (index == -1) continue;
		}
		else if (input == "4") return;
		else {
			cout << "Invalid input." << endl;
			continue;
		}
		break;
	}
	deleteStudent(index);
}

//manual interface for searching for a specific student
void ClassInterface::searchStudentInterface() {
	string input;
	string value;

	int index;

	while (true) {
		cout << "How would you like to identify the student?" << endl
			<< "1. Name" << endl
			<< "2. UsfId" << endl
			<< "3. Email" << endl
			<< "4. Back" << endl;
		getline(cin, input);
		if (input == "1") {
			cout << "Please enter the student's name." << endl;
			getline(cin, value);
			index = getByName(value);
			if (index == -1) continue;
		}
		else if (input == "2") {
			cout << "Please enter the student's UsfId." << endl;
			getline(cin, value);
			index = getById(value);
			if (index == -1) continue;
		}
		else if (input == "3") {
			cout << "Please enter the student's email." << endl;
			getline(cin, value);
			index = getByEmail(value);
			if (index == -1) continue;
		}
		else if (input == "4") return;
		else {
			cout << "Invalid input." << endl;
			continue;
		}
		break;
	}
	printStudent(index);
}

//Function to update a students information
void ClassInterface::updateFieldsInterface() {
	string input;
	string value;
	string field;
	Fields fieldEnum;

	int index;

	//how you want to indentify the student
	while (true) {
		cout << "How would you like to identify the student?" << endl
			<< "1. Name" << endl
			<< "2. UsfId" << endl
			<< "3. Email" << endl
			<< "4. Back" << endl;
		getline(cin, input);
		if (input == "1") {
			cout << "Please enter the student's name." << endl;
			getline(cin, value);
			index = getByName(value);
			if (index == -1) continue;
		}
		else if (input == "2") {
			cout << "Please enter the student's UsfId." << endl;
			getline(cin, value);
			index = getById(value);
			if (index == -1) continue;
		}
		else if (input == "3") {
			cout << "Please enter the student's email." << endl;
			getline(cin, value);
			index = getByEmail(value);
			if (index == -1) continue;
		}
		else if (input == "4") return;
		else {
			cout << "Invalid input." << endl;
			continue;
		}
		break;
	}

	printStudent(index);

	//what field you would like to update for the student
	while (true) {
		cout << "Please enter the number of the field you would like to update. " << endl
			<< "1. Presentation" << endl
			<< "2. Essay 1" << endl
			<< "3. Essay 2" << endl
			<< "4. Term Project" << endl;
		getline(cin, field);
		if (field == "1") fieldEnum = Fields::presentation;
		else if (field == "2") fieldEnum = Fields::essay1;
		else if (field == "3") fieldEnum = Fields::essay2;
		else if (field == "4") fieldEnum = Fields::termProject;
		else {
			cout << "Invalid input." << endl;
			continue;
		}
		break;
	}
	//ask for and then get updated value
	while (true) {
		cout << "Please enter the value you would like to insert into the field." << endl;
		getline(cin, value);
		if (updateField(index, fieldEnum, value) == -1) continue;
		break;
	}

}

//saves the student information to the file
void ClassInterface::writeFile() {
	ofstream fileIn;

	fileIn.open("ClassInfo.txt");

	int classSize = classList.size();

	//seperates each data field with a comma in file
	for (int i = 0; i < classList.size(); i++) {
		fileIn << classList[i].name << ","
			<< classList[i].usfId << ","
			<< classList[i].email << ","
			<< classList[i].presentation << ","
			<< classList[i].essay1 << ","
			<< classList[i].essay2 << ","
			<< classList[i].termProject << ","
			<< "\n";

	}

	fileIn.close();
}

//Loads the information from the file that was saved from previous use
bool ClassInterface::uploadFile(const string& filename) {
	string currentLine;
	ifstream f(filename.c_str());
	if (f) {
		while (getline(f, currentLine)) {
			istringstream linestream(currentLine);
			string studentName, studentId, studentEmail, studentPresentation, studentEssay1, studentEssay2, studentTermProject;
			getline(linestream, currentLine, ',');
			istringstream(currentLine) >> studentName;
			getline(linestream, currentLine, ',');
			istringstream(currentLine) >> studentId;
			getline(linestream, currentLine, ',');
			istringstream(currentLine) >> studentEmail;
			getline(linestream, currentLine, ',');
			istringstream(currentLine) >> studentPresentation;
			getline(linestream, currentLine, ',');
			istringstream(currentLine) >> studentEssay1;
			getline(linestream, currentLine, ',');
			istringstream(currentLine) >> studentEssay2;
			getline(linestream, currentLine, ',');
			istringstream(currentLine) >> studentTermProject;
			getline(linestream, currentLine, ',');
			ClassInterface::addStudent(studentName, studentId, studentEmail, stoi(studentPresentation), stoi(studentEssay1), stoi(studentEssay2), stoi(studentTermProject));
		}
		f.close();
		return true;
	}
	else {
		return false;
	}
}
