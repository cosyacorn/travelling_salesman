CC=gcc
CFLAGS=-Wall
#objects=main.o dist.o

task1: main.o dist.o
	$(CC) $(CFLAGS) -o task1 main.o dist.o

dist.o: dist.c
	gcc -c dist.c -lm
