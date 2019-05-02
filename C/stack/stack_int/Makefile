stack: main.o stack_int.o
	gcc main.o stack_int.o -o stack

main.o: main.c
	gcc -c main.c

stack_int.o: stack_int.c
	gcc -c stack_int.c

clean:
	rm *.o
	rm stack
