#include <stdio.h>
#define DEBUG(a) printf("File: %s, Line in code: %d, Name: %s Value:%d", __FILE__, __LINE__, #a,  (a))
void main(){
    int a = 4;
    DEBUG(a);
}