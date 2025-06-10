#include <stdio.h>
#define SWAP(A,B,TYPE){\
TYPE TEMP;\
TEMP = A;\
A = B;\
B = TEMP;\
}
#define SORT(ARRAY, SIZE, TYPE, COMPARE){\
for(int i = 0; i < SIZE - 1; i++) {\
for(int j = 0; j < SIZE - i - 1; j++) {\
if(ARRAY[j] COMPARE ARRAY[j + 1]) {\
SWAP(ARRAY[j], ARRAY[j+1], TYPE);\
}\
}\
}\
}
void main(){
    int array[5] = {7, 2, 3, 8, 1};
    SORT(array, 5, int, >);
    for(int i = 0; i < 5; i++){
        printf("%d", array[i]);
    }
}