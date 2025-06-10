#include <stdio.h>
#include <stdlib.h>

typedef union{
    long odd;
    short even;
}number;

int main(void){
    number arr[10];
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            arr[i].even = i;
        }
        if(i % 2 != 0){
            arr[i].odd = i;
        }
    }
    printf("Even indexes: \n");
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
            printf("index %d: %hd\n",i , arr[i].even);
        }
    }
    printf("Odd indexes: \n");
    for(int i = 0; i< 10; i++){
        if(i % 2 != 0){
            printf("index %d: %ld\n", i, arr[i].odd);
        }
    }
    }