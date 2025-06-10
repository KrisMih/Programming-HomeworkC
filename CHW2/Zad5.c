#include <stdio.h>
#define SWAP(a, b, TYPE) \ 
TYPE temp = a; \
a = b; \
b = temp;
void main(){
    int a = 4; 
    int b = 5;
    SWAP(a, b, int);
    printf("a = %d, b = %d", a, b);
}