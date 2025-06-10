#include <stdio.h>
#define COMPARE(a,b) ((a)>(b) ? (a) : (b))
void main(){
    printf("%d", COMPARE(5,6));
}