all: main

main: main.o grafo.o
    gcc -o main main.o grafo.o

main.o: main.c grafo.h
    gcc -c main.c

grafo.o: grafo.c grafo.h
    gcc -c grafo.c

clean:
    rm -f *.o main
