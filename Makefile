# Makefile

CC = gcc
CFLAGS = -Wall
TARGET = grafo
OBJS = main.o grafo.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c grafo.h
	$(CC) $(CFLAGS) -c main.c

grafo.o: grafo.c grafo.h
	$(CC) $(CFLAGS) -c grafo.c

clean:
	rm -f *.o $(TARGET)
