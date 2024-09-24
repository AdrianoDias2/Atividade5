CC = gcc
CFLAGS = -Wall -g

all: main

main: main.o grafo.o
	$(CC) $(CFLAGS) -o main main.o grafo.o

main.o: main.c grafo.h
	$(CC) $(CFLAGS) -c main.c

grafo.o: grafo.c grafo.h
	$(CC) $(CFLAGS) -c grafo.c

clean:
	rm -f *.o main
