CC=gcc
CFLAGS=-Wall -ansi -std=c99 -lMLV
OBJ=main.o graphics.o dames.o

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

graphics.o: graphics.c graphics.h
	$(CC) -c graphics.c $(CFLAGS)

dames.o: dames.c dames.h
	$(CC) -c dames.c $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f main
