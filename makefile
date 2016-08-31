studentRecord.o: studentRecord.cpp
	g++ -Wall -c -std=c++11 studentRecord.cpp -o build/studentRecord.o

studentDao.o: studentDao.cpp
	g++ -Wall -c -std=c++11 studentDao.cpp -o build/studentDao.o
	
program.o: program.cpp
	g++ -Wall -c -std=c++11 program.cpp -o build/program.o

all : program.o studentDao.o studentRecord.o
	g++ -Wall build/program.o build/studentDao.o build/studentRecord.o -o build/program
