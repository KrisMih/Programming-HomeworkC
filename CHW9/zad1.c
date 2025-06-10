#include <stdio.h>
void main(){
    double a;
    double b;
    printf("Enter value for a: ");
    scanf("%lf", &a);
    printf("Enter value for b: ");
    scanf("%lf", &b);
    double * pa = &a;
    printf("adress of a: %p\n", pa);
    double * pb = &b;
    printf("adress of b: %p\n", pb);
    printf("The value of pointer a is:%lf\n", *pa);
    printf("The value of pointer b is:%lf\n", *pb);
}