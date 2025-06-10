#include <stdio.h>
#include <stdlib.h>
#include "transformation.h"
void main(){
const char* valid = "-123";
const char* invalid = "12ab23";
transformation result1 = string_to_number(valid);
    if(result1.error[0] == '\0'){
        printf("Entry: \"%s\" => Result: %ld\n", valid, result1.result);
}
    else {
        printf("Entry: \"%s\" => Error: %s\n", valid, result1.error);
}
transformation result2 = string_to_number(invalid);
    if (result2.error[0] == '\0') {
        printf("Entry: \"%s\" => Result: %ld\n", invalid, result2.result);
} 
    else {
        printf("Result: \"%s\" => Error: %s\n", invalid, result2.error);
}
}