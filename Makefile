CFLAGS=-Wall -g
exec: main.o linked_list.o 
	gcc $(CFLAGS) main.o linked_list.o -o exec
main.o: main.c
	gcc $(CFLAGS) -c main.c
linked_list.o: linked_list.c
	gcc $(CFLAGS) -c linked_list.c
clean:
	rm *.o
	rm exec
