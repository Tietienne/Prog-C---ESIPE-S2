# Makefile TP 14

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
OBJ=larger_file.o node.o

larger_file: $(OBJ)
	$(CC) -o larger_file $(OBJ) $(CFLAGS)

node.o: node.c node.h
	$(CC) -c node.c $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f larger_file