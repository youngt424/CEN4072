#ifndef STUDENTDAO_H
#define STUDENTDAO_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <vector>
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
		//Creates dao from student data found in file "location"
		StudentDao(string location);
		
		/*
		Precondition: None
		Postcondition: returns true if there is a file location set for saving
		*/
		bool canSave();
		
		/*
		Precondition: None
		Postcondition: student data is saved to a specified file
		*/
		void save();
		
		/*
		Precondition: an input string as a file location
		Postcondition: student data is saved to the specified file
		*/
		void saveAs(string location);
		
		int count();
		
		/*
		Precondition: a student record 
		Postcondition: the student information is saved to the dao
		*/
		void addRecord(Student* record);
		
		/*
		Precondition: an integer index of a student record in the dao
		Postcondition: returns record of the student at the specified index in dao
		*/
		Student* readRecord(int index);
		
		/*
		Precondition: A file location has been set to save the data
		Postcondition: student data is saved to the specified file
		*/
		int readRecord(string usfId);
		
		/*
		Precondition: an integer index of the student record in the dao
		Postcondition: the student at the specified index in dao is deleted
		*/
		void deleteRecord(int index);
		
		/*
		Precondition: an input string as keyword to search for in the dao
		Postcondition: a vector of indexes specifiing students that match the keyword search
		*/
		vector<int> search(string keyword);

		/*
		Precondition: None
		Postcondition: returns a randomized hex string of length 24
		*/
		string genRandomHex();
};

#endif
