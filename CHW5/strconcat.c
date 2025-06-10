#include <stdio.h>
#include "mystrings.h"
#define MAX_LENGTH 50
int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Input only 2 strings");
        return 1;
    }
    if(strlength(argv[1]) > MAX_LENGTH || strlength(argv[2]) > MAX_LENGTH)
{
    printf("The string is too long");
    return 1;
}
   strconcat(argv[1], argv[2]);
    printf("%s", argv[1]);
    return 0;
}