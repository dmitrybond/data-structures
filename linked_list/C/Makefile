FLAGS=-Wall -g
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
CC=gcc
else ifeq ($(UNAME), Darwin)
CC=clang
endif

test: main.o ll.o 
	$(CC) $(FLAGS) ll.o main.o -o test
main.o: main.c
	$(CC) $(FLAGS) -c main.c
ll.o: ll.c
	$(CC) $(FLAGS) -c ll.c
clean:
	rm *.o
	rm test
