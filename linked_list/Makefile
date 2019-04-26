CFLAGS=-Wall -g
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
CC=gcc
CPP=g++
endif
ifeq ($(UNAME), Darwin)
CC=clang
CPP=clang++
endif
ll_c: main.o ll.o 
	$(CC) $(CFLAGS) ll.o main.o -o ll_c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
ll.o: ll.c
	$(CC) $(CFLAGS) -c ll.c
ll_cpp: ll.cpp
	$(CPP) $(CFLAGS) ll.cpp -o ll_cpp
clean:
	rm *.o
	rm ll_c
clean_cpp:
	rm ll_cpp
