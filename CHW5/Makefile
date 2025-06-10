CC = gcc
CFLAGS = -Wall -std=c99

mystrings.o: mystrings.c mystrings.h
	$(CC) $(CFLAGS) -c mystrings.c -o mystrings.o

strlength.out: strlength.c mystrings.o
	$(CC) $(CFLAGS) strlength.c mystrings.o -o strlength.out

strconcat.out: strconcat.c mystrings.o
	$(CC) $(CFLAGS) strconcat.c mystrings.o -o strconcat.out

strcompare.out: strcompare.c mystrings.o
	$(CC) $(CFLAGS) strcompare.c mystrings.o -o strcompare.out

help.out: help.c
	$(CC) $(CFLAGS) help.c -o help.out

clean:
	rm -f *.o *.out

all: help.out  strlength.out strconcat.out strcompare.out