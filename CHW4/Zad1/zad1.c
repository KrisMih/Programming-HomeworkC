#include <stdio.h>
#define SUM(A,B) ((A+B) * (A+B))
void main(){
    int a = 5, b = 6;
    printf("The sum of (A+B) ^ 2 = %d", SUM(a,b));
}