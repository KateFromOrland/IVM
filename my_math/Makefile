CC=g++

all: project

project: libproject.a main.cpp
	$(CC) main.cpp -o project -L. -lproject

libproject.a: vector.o matrix.o
	ar cr libproject.a matrix.o vector.o

vector.o: vector.h vector.cpp 
	$(CC) -c vector.cpp

matrix.o: matrix.h matrix.cpp
	$(CC) -c matrix.cpp
clean:
	rm -f *.o project *.a
