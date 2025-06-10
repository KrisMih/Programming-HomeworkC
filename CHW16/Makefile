all: zad2.out

zad2.out: zad2.c DynamicArray.o
	gcc zad2.c DynamicArray.o -o zad2.out

DynamicArray.o: DynamicArray.c DynamicArray.h util.h
	gcc -c DynamicArray.c -o DynamicArray.o

clean:
	rm -f *.o *.out