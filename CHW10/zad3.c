#include <stdio.h>
void strhalf(char string[], char **pointer){
    int length = 0;
    char *tempptr = string;
    while (*tempptr != 0){
        length++;
        tempptr++;
    }
    *pointer = string + (length / 2);
}

void main(){
    char string[] = "Ivan";
    char *pointer;
    strhalf(string, &pointer);
    printf("The second half of the string: %s", pointer);
}