#ifndef STUDENTDAO_H
#define STUDENTDAO_H

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class StudentDao
{
	private:
		vector<Student*> students;
	
	public:
		StudentDao();
		StudentDao(string location);

		void Save();
		void SaveAs(string location);
		
		int Count();
		
		void Create(Student* record);
		Student* Read(int id);
		void Update(Student* record);
		void Delete(int id);
		
		vector<int> Search(string keyword);
};

#endif
