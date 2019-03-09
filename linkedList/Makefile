CFLAGS=-Wall -g
CC=clang
exec: main.o ll_generic.o 
	$(CC) $(CFLAGS) ll_generic.o main.o -o exec
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
ll_generic.o: ll_generic.c
	$(CC) $(CFLAGS) -c ll_generic.c
clean:
	rm *.o
	rm exec
