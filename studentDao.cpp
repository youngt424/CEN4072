#include "studentDao.h"

StudentDao::StudentDao()
{
	oldLocationSet = false;
}

StudentDao::StudentDao(string location)
{
	ifstream file(location.c_str());
	string line;
	
	while (getline(file, line) && line.length())
	{
		students.push_back(new Student(line));
	}
	
	oldLocation = location;
	oldLocationSet = true;
}

bool StudentDao::canSave()
{
	return oldLocationSet;
}

void StudentDao::save()
{
	if (!oldLocationSet)
	{
		throw "Save location not set.";
	}
	
	if (access(oldLocation.c_str(), F_OK) != -1)
	{
		remove(oldLocation.c_str());
	}
	
	ofstream file;
	file.open(oldLocation);
	
	for (unsigned int index = 0; index < students.size(); index++)
	{
		file << students.at(index)->toString() << "\n";
	}
	
	file.close();
}

void StudentDao::saveAs(string location)
{
	oldLocation = location;
	oldLocationSet = true;
	save();
}

int StudentDao::count()
{
	return students.size();
}

void StudentDao::addRecord(Student* record)
{
	if (record == NULL)
	{
		throw "New student records cannot be NULL.";
	}
	
	for (unsigned int index = 0; index < students.size(); index++)
	{
		if (students.at(index)->getUsfId().compare(record->getUsfId()) == 0)
		{
			throw "Duplicate USF ID.";
		}
	}
	
	students.push_back(record);
}

Student* StudentDao::readRecord(int index)
{
	return students.at(index);
}

int StudentDao::readRecord(string usfId)
{
	transform(usfId.begin(), usfId.end(), usfId.begin(), ::toupper);
	
	for (unsigned int index = 0; index < students.size(); index++)
	{
		if (students.at(index)->getUsfId().compare(usfId) == 0)
		{
			return index;
		}
	}
	
	return -1;
}

void StudentDao::deleteRecord(int index)
{
	students.erase(students.begin() + index);
}

vector<int> StudentDao::search(string keyword)
{
	vector<int> returnValue;
	
	for (unsigned int index = 0; index < students.size(); index++)
	{
		if (students.at(index)->search(keyword))
		{
			returnValue.push_back(index);
		}
	}
	
	return returnValue;
}
