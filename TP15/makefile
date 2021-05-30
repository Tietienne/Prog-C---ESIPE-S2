# Makefile TP 15

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99 -lreadline
OBJ=main.o pile.o

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

pile.o: pile.c pile.h
	$(CC) -c pile.c $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f main