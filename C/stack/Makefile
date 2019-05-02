FLAGS=-Wall
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
CC=gcc
else ifeq ($(UNAME), Darwin)
CC=clang
endif

stack: main.o stack.o
	$(CC) $(FLAGS) main.o stack.o -o stack

main.o: main.c
	$(CC) $(FLAGS) -c main.c

stack.o: stack.c
	$(CC) $(FLAGS) -c stack.c
clean:
	rm *.o
	rm stack
