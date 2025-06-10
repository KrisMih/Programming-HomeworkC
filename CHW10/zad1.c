#include <stdio.h>
int strlen(char string[]){
    const char *ptr = string;
    while(*ptr != 0){
        ptr++;
    }
    return ptr - string;
}

void main(){
    char string[] = "Ivan";
    int length = strlen(string);
    printf("The length of the string is: %d", length);
}