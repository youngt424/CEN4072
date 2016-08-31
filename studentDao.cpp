#include "studentDao.h"

vector<string> split(string str)
{
	vector<string> returnValue;
	bool escaped = false, firstChar = true;
	char c;
	string cell;
	
	for (unsigned int index = 0; index < str.length(); index++)
	{
		c = str.at(index);
		if (escaped)
		{
			if (c == '\"')
			{
				if (index + 1 < str.length() && str.at(index + 1) == '\"')
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
				returnValue.push_back(cell.substr(0, cell.length()));
				cell.clear();
			}
			else
			{
				returnValue.push_back("");
			}
			firstChar = true;
		}
		else
		{
			cell.append(1, c);
			firstChar = false;
		}
	}

	returnValue.push_back(cell.substr(0, cell.length()));

	return returnValue;
}

StudentDao::StudentDao()
{
}
StudentDao::StudentDao(string location)
{
	ifstream file(location);
	string line;
	
	while (getline(file, line))
	{
		
	}
}


void StudentDao::Save()
{
}
void StudentDao::SaveAs(string location)
{
}

int StudentDao::Count()
{
	return 0;
}

void StudentDao::Create(StudentRecord* record)
{
}
StudentRecord* StudentDao::Read(int id)
{
	return NULL;
}
void StudentDao::Update(StudentRecord* record)
{
}
void StudentDao::Delete(int id)
{
}

vector<int> StudentDao::Search(string keyword)
{
	vector<int> returnValue;
	
	return returnValue;
}
