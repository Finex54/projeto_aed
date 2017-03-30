CC=gcc
CFLAGS=-g -Wall

burster: main.o lista.o matriz.o
	$(CC) $(CFLAGS) -o burster main.o list.o utils.o matrix.o

main.o: main.c listas.h matriz.h
	$(CC) -c $(CFLAGS) main.c

matriz.o: matriz.c matriz.h
	$(CC) -c $(CFLAGS) matriz.c

listas.o: listas.c listas.h matriz.z
	$(CC) -c $(CFLAGS) listas.c

clean::
	    rm -f *.o core a.out burster *~



