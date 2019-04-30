stack: main.o stack.o
	gcc main.o stack.o -o stack

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

clean:
	rm *.o
	rm stack
