#include <stdio.h>
#include "mystrings.h"
int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Input oly 2 strings");
    }
    int result = strcompare(argv[1], argv[2]);
    if(result == 0){
        printf("The two strings are lexicographically equal");
    }
    if(result == 1){
        printf("The first string is lexicographically after the second string");
    }
    if(result == -1){
        printf("The second string is lexicographically after the first string");
    }
    return 0;
}