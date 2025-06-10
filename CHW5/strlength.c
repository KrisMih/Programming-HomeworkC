#include <stdio.h>
#include "mystrings.h"
int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Input only 1 string!");
        return 1;
    }
printf("The length of the inputed string is:%d", strlength(argv[1]));
return 0;
}