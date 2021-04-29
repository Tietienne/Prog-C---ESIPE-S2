CC=gcc
CFLAGS=-Wall -ansi -std=c99

all:simplelist hachage

simplelist: simplelist.o 
	$(CC) -o simplelist simplelist.o $(CFLAGS)

hachage: hachage.o
	$(CC) -o hachage hachage.o $(CFLAGS)

clean: 
	rm -f *.o
	rm -f *~
	rm -f main
