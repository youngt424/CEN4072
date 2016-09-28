#ifndef STUDENTDAO_H
#define STUDENTDAO_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <vector>
#include <ctime>
#include "student.h"

using namespace std;

class StudentDao
{
	private:
		bool oldLocationSet;
		vector<Student*> students;
		string oldLocation;
	
	public:
		StudentDao();
		StudentDao(string location);

		bool canSave();
		void save();
		void saveAs(string location);
		
		int count();
		
		void addRecord(Student* record);
		Student* readRecord(int index);
		int readRecord(string usfId);
		void deleteRecord(int index);
		string genRandomHex();
		
		vector<int> search(string keyword);
};

#endif
