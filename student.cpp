#include "student.h"

Student::Student()
{
	name = "";
	usfId = "";
	email = "";
	gradePresentation = 0;
	gradeEssay1 = 0;
	gradeEssay2 = 0;
	gradeTermProject = 0;
	getInput(true);
}

Student::Student(string _name, string _usfId, string _email, double _gradePresentation, double _gradeEssay1, double _gradeEssay2, double _gradeTermProject)
{
	setName(_name);
	setUsfId(_usfId);
	setEmail(_email);
	setGradePresentation(_gradePresentation);
	setGradeEssay1(_gradeEssay1);
	setGradeEssay2(_gradeEssay2);
	setGradeTermProject(_gradeTermProject);
}

Student::Student(string line)
{
	vector<string> splitLine;
	bool escaped = false, firstChar = true;
	char c;
	string cell;
	
	for (unsigned int index = 0; index < line.length(); index++)
	{
		c = line.at(index);
		if (escaped)
		{
			if (c == '“')
			{
				if (index < line.length() && line.at(index) == '\"')//index needs to be index+1
				{
					index++;
					cell.append(1, '\"');
				}
				else
				{
					escaped = false;
				}
			}
			else
			{
				cell.append(1, c);
			}
		}
		else if (firstChar && c == '\"')
		{
			escaped = true;
			firstChar = false;
		}
		else if (c == ',')
		{
			if (cell.length() > 0)
			{
				splitLine.push_back(cell.substr(0, cell.length()));
				cell.clear();
			}
			else
			{
				splitLine.push_back("");
			}
			firstChar = true;
		}
		else
		{
			cell.append(1, c);
			firstChar = false;
		}
	}

	splitLine.push_back(cell.substr(0, cell.length()));
	
	name = splitLine.at(0);
	usfId = splitLine.at(1);
	email = splitLine.at(2);
	gradePresentation = atof(splitLine.at(3).c_str());
	gradeEssay1 = atof(splitLine.at(4).c_str());
	gradeEssay2 = atof(splitLine.at(5).c_str());
	gradeTermProject = atof(splitLine.at(6).c_str());
}

bool Student::promptToChange(string fieldName)
{
	cout << "Do you want to change " << fieldName << " (yes or no)?\n";
	
	string line;
	getline(cin, line);
	transform(line.begin(), line.end(), line.begin(), ::toupper);
	
    size_t results = line.find("YES");
    return results != string::npos;
}

void Student::getInput(bool isNew)
{
	string line;
	bool valueSet;
	
	if (isNew)
	{
		valueSet = false;
		while (!valueSet)
		{
			try
			{
				cout << "Enter the USF ID in the format of U00000000:\n";
				getline(cin, line);
				setUsfId(line);
				valueSet = true;
			}
			catch (char const* error)
			{
				cout << "Error: " << error << "\n";
			}
		}
	}
	
	if (isNew || promptToChange("the student's name"))
	{
		valueSet = false;
		while (!valueSet)
		{
			try
			{
				cout << "Enter the name:\n";
				getline(cin, line);
				setName(line);
				valueSet = true;
			}
			catch (char const* error)
			{
				cout << "Error: " << error << "\n";
			}
		}
	}
	
	if (isNew || promptToChange("the student's e-mail"))
	{
		valueSet = false;
		while (!valueSet)
		{
			try
			{
				cout << "Enter the e-mail:\n";
				getline(cin, line);
				setEmail(line);
				valueSet = true;
			}
			catch (char const* error)
			{
				cout << "Error: " << error << "\n";
			}
		}
	}
	
	if (isNew || promptToChange("the student's presentation grade"))
	{
		valueSet = false;
		while (!valueSet)
		{
			try
			{
				cout << "Enter the grade value between 0 to 1:\n";
				getline(cin, line);
				setGradePresentation(atof(line.c_str()));
				valueSet = true;
			}
			catch (char const* error)
			{
				cout << "Error: " << error << "\n";
			}
		}
	}
	
	if (isNew || promptToChange("the student's essay 1 grade"))
	{
		valueSet = false;
		while (!valueSet)
		{
			try
			{
				cout << "Enter the grade value between 0 to 1:\n";
				getline(cin, line);
				setGradeEssay1(atof(line.c_str()));
				valueSet = true;
			}
			catch (char const* error)
			{
				cout << "Error: " << error << "\n";
			}
		}
	}
	
	if (isNew || promptToChange("the student's essay 2 grade"))
	{
		valueSet = false;
		while (!valueSet)
		{
			try
			{
				cout << "Enter the grade value between 0 to 1:\n";
				getline(cin, line);
				setGradeEssay2(atof(line.c_str()));
				valueSet = true;
			}
			catch (char const* error)
			{
				cout << "Error: " << error << "\n";
			}
		}
	}
	
	if (isNew || promptToChange("the student's term project grade"))
	{
		valueSet = false;
		while (!valueSet)
		{
			try
			{
				cout << "Enter the grade value between 0 to 1:\n";
				getline(cin, line);
				setGradeTermProject(atof(line.c_str()));
				valueSet = true;
			}
			catch (char const* error)
			{
				cout << "Error: " << error << "\n";
			}
		}
	}
}

void Student::getInput()
{
	getInput(false);
}

bool Student::search(string keyword)
{
    size_t results;
    
    results = name.find(keyword);
    if (results != string::npos)
    {
        return true;
    }
    
    results = usfId.find(keyword);
    if (results != string::npos)
    {
        return true;
    }
    
    results = usfId.find(keyword);
    if (results != string::npos)
    {
        return true;
    }
    
    results = email.find(keyword);
    if (results != string::npos)
    {
        return true;
    }
    
    stringstream numbers;
    numbers << gradePresentation << "\t" << gradeEssay1 << "\t" << gradeEssay2 << "\t" << gradeTermProject;
    
    results = numbers.str().find(keyword);
    if (results != string::npos)
    {
        return true;
    }
    
    return false;
}

string Student::toString()
{
	stringstream returnValue;
	
	returnValue << "\"";
	for (unsigned int i = 0; i < name.length(); i++)
	{
		if (name[i] == '"')
		{
			returnValue << "\"\"";
		}
		else
		{
			returnValue << name[i];
		}
	}
	returnValue << "\",";

	returnValue << "\"";
	for (unsigned int i = 0; i < usfId.length(); i++)
	{
		if (usfId[i] == '"')
		{
			returnValue << "\"\"";
		}
		else
		{
			returnValue << usfId[i];
		}
	}
	returnValue << "\",";

	returnValue << "\"";
	for (unsigned int i = 0; i < email.length(); i++)
	{
		if (email[i] == '"')
		{
			returnValue << "\"\"";
		}
		else
		{
			returnValue << email[i];
		}
	}
	returnValue << "\",";

	returnValue << "\"" << gradePresentation << "\",\"" << gradeEssay1 << "\",\"" << gradeEssay2 << "\",\"" << gradeTermProject << "\"";

	return returnValue.str();
}

void Student::print()
{
	cout << "\tName:               " << name << "\n";
	cout << "\tUSF ID:             " << usfId << "\n";
	cout << "\tE-Mail:             " << email << "\n";
	cout << "\tPresentation Grade: " << round(gradePresentation * 100) << "\n";
	cout << "\tEssay 1 Grade:      " << round(gradeEssay1 * 100) << "\n";
	cout << "\tEssay 2 Grade:      " << round(gradeEssay2 * 100) << "\n";
	cout << "\tTerm Proj. Grade:   " << round(gradeTermProject * 100) << "\n";
}

string Student::getName()
{
	return name;
}

void Student::setName(string _name)
{
	name = _name;
}

string Student::getUsfId()
{
	return usfId;
}
void Student::setUsfId(string _usfId)
{
	if (usfId.length())
	{
		throw "The USF ID cannot be changed.";
	}
	
	if (_usfId.length() != 9 || (_usfId[0] != 'u' && _usfId[0] != 'U'))
	{
		throw "The USF ID needs to be in the format of U00000000.";
	}
	
	for (unsigned int i = 1; i < _usfId.length(); i++)
	{
		if (_usfId[i] < '0' || _usfId[i] > '9')
		{
			throw "The USF ID needs to be in the format of U00000000.";
		}
	}
	
	transform(_usfId.begin(), _usfId.end(), _usfId.begin(), ::toupper);
	
	usfId = _usfId;
}

string Student::getEmail()
{
	return email;
}
void Student::setEmail(string _email)
{
	size_t results = _email.find("@");
    if (results != string::npos)
	{
		email = _email;
	}
	else
	{
		throw "Invalid e-mail address.";
	}
}

double Student::getGradePresentation()
{
	return gradePresentation;
}
void Student::setGradePresentation(double _gradePresentation)
{
	if (_gradePresentation < 0 || _gradePresentation > 1)
	{
		throw "Invalid grade.";
	}
	gradePresentation = _gradePresentation;
}

double Student::getGradeEssay1()
{
	return gradeEssay1;
}
void Student::setGradeEssay1(double _gradeEssay1)
{
	if (_gradeEssay1 < 0 || _gradeEssay1 > 1)
	{
		throw "Invalid grade.";
	}
	gradeEssay1 = _gradeEssay1;
}

double Student::getGradeEssay2()
{
	return gradeEssay2;
}
void Student::setGradeEssay2(double _gradeEssay2)
{
	if (_gradeEssay2 < 0 || _gradeEssay2 > 1)
	{
		throw "Invalid grade.";
	}
	gradeEssay2 = _gradeEssay2;
}

double Student::getGradeTermProject()
{
	return gradeTermProject;
}
void Student::setGradeTermProject(double _gradeTermProject)
{
	if (_gradeTermProject < 0 || _gradeTermProject > 1)
	{
		throw "Invalid grade.";
	}
	gradeTermProject = _gradeTermProject;
}
