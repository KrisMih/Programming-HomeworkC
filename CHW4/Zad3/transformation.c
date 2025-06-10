#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "transformation.h"
transformation string_to_number(const char* string){
    transformation result;
    char *endptr;
    result.result = 0;
    result.error[0] = '\0';
    result.result = strtol(string, &endptr, 10);
    if(*endptr != '\0'){
        strcpy(result.error, "Invalid string");
        result.result = 0;
    }
    else{
        result.error[0] = '\0';
    }
    return result;
}