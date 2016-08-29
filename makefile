program.o: program.cpp
	g++ -Wall -c -std=c++11 program.cpp -o build/program.o

all : program.o
	g++ -Wall build/program.o -o build/program
