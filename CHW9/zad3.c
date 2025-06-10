#include <stdio.h>
void swap(void *a, void *b){
    int *pa = (int *)a;
    int *pb = (int *)b;
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void main(){
    int a = 10, b = 6;
    swap(&a, &b);
    printf("%d%d", a, b);
}