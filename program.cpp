#include <iostream>
#include <map>
#include <string>
#include "student.h"
#include "studentDao.h"

using namespace std;

typedef void (*OptionFunction)(void);

map<char, OptionFunction> options;
StudentDao* dao = NULL;
bool keepRunning = true;
char option;

int getByUsfId()
{
	cout << "Enter the USF ID for the student:\n";
	string usfId;
	getline(cin, usfId);
	
	int returnValue = dao->readRecord(usfId);
	
	if (returnValue == -1)
	{
		cout << "No student was found.\n";
	}
	
	return returnValue;
}

void addStudent()
{
	try
	{
		dao->addRecord(new Student());
	}
	catch (char const* error)
	{
		cout << "Error: " << error << "\n";
	}
}
bool showAddStudent()
{
	cout << "\t" << option << ") Add Student\n";
	options[option] = &addStudent;
	option++;
	return true;
}
void exitApp()
{
	keepRunning = false;
}
bool showExitApp()
{
	cout << "\t" << option << ") Exit\n";
	options[option] = &exitApp;
	option++;
	return true;
}
void modifyStudent()
{
	int studentIndex = getByUsfId();
	if (studentIndex == -1)
	{
		return;
	}
	Student* student = dao->readRecord(studentIndex);
	student->getInput();
}
bool showModifyStudent()
{
	cout << "\t" << option << ") Modify Student\n";
	options[option] = &modifyStudent;
	option++;
	return true;
}
void removeStudent()
{
	int studentIndex = getByUsfId();
	if (studentIndex > -1)
	{
		dao->deleteRecord(studentIndex);
	}
}
bool showRemoveStudent()
{
	cout << "\t" << option << ") Remove Student\n";
	options[option] = &removeStudent;
	option++;
	return true;
}
void save()
{
	dao->save();
}
bool showSave()
{
	if (dao->canSave())
	{
		cout << "\t" << option << ") Save Database File\n";
		options[option] = &save;
		option++;
		return true;
	}
	return false;
}
void saveAs()
{
	cout << "Enter the file path to save to:\n";
	string file;
	getline(cin, file);
	dao->saveAs(file);
}
bool showSaveAs()
{
	cout << "\t" << option << ") Save Database File to Another Location\n";
	options[option] = &saveAs;
	option++;
	return true;
}
void search()
{
	cout << "Enter the keyword to search for:\n";
	string keyword;
	getline(cin, keyword);
	
	vector<int> matches = dao->search(keyword);
	
	if (matches.size())
	{
		for (unsigned int index = 0; index < matches.size(); index++)
		{
			cout << "Match " << (index + 1) << ":\n";
			Student* student = dao->readRecord(index);
			student->print();
		}
	}
	else
	{
		cout << "No matches\n";
	}
}
bool showSearch()
{
	cout << "\t" << option << ") Search\n";
	options[option] = &search;
	option++;
	return true;
}
void showAll()
{
	if (dao->count())
	{
		for (int index = 0; index < dao->count(); index++)
		{
			cout << "Student " << (index + 1) << ":\n";
			Student* student = dao->readRecord(index);
			student->print();
		}
	}
	else
	{
		cout << "No student records.\n";
	}
}
bool showShowAll()
{
	cout << "\t" << option << ") Show all Students\n";
	options[option] = &showAll;
	option++;
	return true;
}
bool nextRequest()
{
	cout << "Please select an option:\n";
	option = 'A';
	options.clear();
	
	showAddStudent();
	showExitApp();
	showModifyStudent();
	showRemoveStudent();
	showSave();
	showSaveAs();
	showSearch();
	showShowAll();
	
	string line;
	getline(cin, line);
	
	char selectedOption = toupper(line[0]);
	
	map<char, OptionFunction>::iterator match = options.find(selectedOption);
	
	if (match == options.end())
	{
		cout << "Bad Selection Try Again\n";
	}
	else
	{
		match->second();
	}
	
	return keepRunning;
}

int main(int argc, char* argv[])
{
	dao = argc == 2 ? new StudentDao(argv[1]) : new StudentDao();
	
	cout << "Welcome to the Student Maintenance System\n\n";
	
	while (nextRequest())
	{
	}
}
