#include <stdio.h>
#include <string.h>
void remove_newline(char *string){
    char *newline = strchr(string, '\n');
    if(newline) {
        *newline = '\0';        
    }
}

void main(){
    char string[100];
    printf("Enter a string: \n");
    if(fgets(string, 100, stdin)){
        remove_newline(string);
        printf("Result after removing the new line: %s\n", string);
    }
}