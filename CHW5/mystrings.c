#include <stdio.h>
#include "mystrings.h"
int strlength(const char* string){
    int length = 0;
    while(string[length] != '\0'){
        length++;
    }
    return length;
}
void strconcat(char *string1, const char* string2){
int i = 0;
while(string1[i] != '\0'){
    i++;
}
int j = 0;
while(string2[i] != '\0'){
string1[i] = string2[j];
i++;
j++;
}
string1[i + j] = '\0';
}
int strcompare(const char* string1, const char* string2){
    int i = 0;
    while(string1[i] != '\0' && string2[i] != '\0'){
        if(string1[i] < string2[i]){
            return -1;
        }
        if(string1[i] > string2[i]){
            return 1;
        }
        i++;
    }
    if(string1[i] == '\0' && string2[i] == '\0'){
        return 0;   
    }
}