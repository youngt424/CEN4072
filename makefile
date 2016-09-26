student.o: student.cpp student.h
	g++ -Wall -c -std=c++11 student.cpp -o build/student.o

studentDao.o: studentDao.cpp studentDao.h student.o
	g++ -Wall -c -std=c++11 studentDao.cpp -o build/studentDao.o

program.o: program.cpp student.o studentDao.o
	g++ -Wall -c -std=c++11 program.cpp -o build/program.o

all: program.o student.o studentDao.o
	g++ -Wall build/program.o build/student.o build/studentDao.o -o build/program

