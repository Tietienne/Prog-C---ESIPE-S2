# Makefile TP 15

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99 -lreadline -L. -lpile -Wl,-rpath,.
OBJ=main.o

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f main