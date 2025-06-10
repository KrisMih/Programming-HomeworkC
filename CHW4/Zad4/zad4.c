#include <stdio.h>
#include <math.h>
int main(){
    long array[5] = {1,2,3,4,5};
    for(int i =0; i < 5; i++){
        array[i] = (int)pow(array[i], 4);
        printf("%ld\n", array[i]);
    }
return 0;
}