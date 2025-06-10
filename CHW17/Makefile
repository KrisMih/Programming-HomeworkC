all: zad.out

LinkedList.o: LinkedList.h LinkedList.c
	gcc -c LinkedList.c -o LinkedList.o

zad.out: zad.c LinkedList.o
	gcc zad.c LinkedList.o -o zad.out

clean:
	rm -f *.o *.out