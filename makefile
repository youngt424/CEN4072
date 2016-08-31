studentRecord.o: Student.cpp
	g++ -Wall -c -std=c++11 Student.cpp -o build/Student.o

studentDao.o: studentDao.cpp
	g++ -Wall -c -std=c++11 studentDao.cpp -o build/studentDao.o
	
program.o: program.cpp
	g++ -Wall -c -std=c++11 program.cpp -o build/program.o

all : program.o studentDao.o Student.o
	g++ -Wall build/program.o build/studentDao.o build/Student.o -o build/program
