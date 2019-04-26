CC=gcc
FLAGS=-Wall -g
exec: main.o ht.o prime.o
	$(CC) $(FLAGS) main.o ht.o prime.o -o exec -lm

main.o: main.c
	$(CC) $(FLAGS) -c main.c

ht.o: ht.c
	$(CC) $(FLAGS) -c ht.c

prime.o: prime.c
	$(CC) $(FLAGS) -c prime.c

clean:
	rm -f *.o
	rm -f exec
