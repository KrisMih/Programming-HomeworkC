#include <stdio.h>
int NOD(int a,int b){
    int temp;
    while(b != 0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int NOK(int a,int b){
    return (a * b) / NOD(a,b);
}
void main(){
    int a = 12, b = 18;
    printf("NOK:%d", NOK(a,b));
}
