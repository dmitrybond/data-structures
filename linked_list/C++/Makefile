FLAGS=-Wall -g -std=c++11
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CC=g++
else ifeq ($(UNAME), Darwin)
CC=clang++
endif

test: main.o
	$(CC) $(FLAGS) main.o -o test
main.o: main.cpp
	$(CC) $(FLAGS) -c main.cpp
clean:
	rm *.o
	rm test
