#include <stdio.h>
#include "DynamicArray.h"

int find_element_by_value(DynamicArray * dynArr, int element){
    for(int i = 0; i < dynArr->size; i++){
        if(dynArr->buffer[i] == element){
            return i;
        }
    }
    return -1;
}

int main(void){
    int initialCapacity = 2;
    DynamicArray  dynArr = init(initialCapacity);
    pushBack(&dynArr, 10);
    pushBack(&dynArr, 15);
    pushBack(&dynArr, 20);
    printf("%d", find_element_by_value(&dynArr, 20));
}