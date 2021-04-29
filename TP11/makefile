CC=gcc
CFLAGS=-Wall -ansi -std=c99 -lMLV
OBJ=main.o graphics.o taquin.o

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

graphics.o: graphics.c graphics.h
	$(CC) -c graphics.c $(CFLAGS)

taquin.o: taquin.c taquin.h
	$(CC) -c taquin.c $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f main
