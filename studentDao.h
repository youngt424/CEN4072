#ifndef STUDENTDAO_H
#define STUDENTDAO_H

#include <iostream>
#include <string>
#include <vector>
#include "studentRecord.h"

using namespace std;

class StudentDao
{
	private:
		vector<StudentRecord*> students;
	
	public:
		StudentDao();
		StudentDao(string location);

		void Save();
		void SaveAs(string location);
		
		int Count();
		
		void Create(StudentRecord* record);
		StudentRecord* Read(int id);
		void Update(StudentRecord* record);
		void Delete(int id);
		
		vector<int> Search(string keyword);
};

#endif