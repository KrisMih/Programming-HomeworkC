#include <stdio.h>
int compareasc(const void *a, const void *b) {
    const int *pa = (const int *)a;
    const int *pb = (const int *)b;
    if (*pa > *pb){
        return 1;
    }
    if (*pa < *pb){
        return -1;
    }
    return 0;
}

int comparedesc(const void *a, const void *b) {
    const int *pa = (const int *)a;
    const int *pb = (const int *)b;
    if (*pa < *pb){ 
        return 1;
    }
    if (*pa > *pb){
        return -1;
    }
    return 0;
}

void main() {
    int a = 10, b = 6;
    printf("compareasc(%d, %d) = %d\n", a, b, compareasc(&a, &b));
    printf("compareasc(%d, %d) = %d\n", b, a, compareasc(&b, &a));
    printf("compareasc(%d, %d) = %d\n", a, a, compareasc(&a, &a));
    printf("comparedesc(%d, %d) = %d\n", a, b, comparedesc(&a, &b));
    printf("comparedesc(%d, %d) = %d\n", b, a, comparedesc(&b, &b));
    printf("comparedesc(%d, %d) = %d\n", a, a, comparedesc(&a, &a));
}
