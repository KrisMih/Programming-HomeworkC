#include <stdio.h>
#include <limits.h>
#include <string.h> 
#include "safeint.h"
SafeResult safeadd(int a, int b){
SafeResult result;
if((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)){
    result.errorflag = 1;
    result.value = 0;
}
else{
    result.errorflag = 0;
    result.value = a + b;
}
return result;
}
SafeResult safesubtract(int a, int b){
SafeResult result;
if((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b)){
    result.errorflag = 1;
    result.value = 0;
}
else{
    result.errorflag = 0;
    result.value = a - b;
}
return result;
}
SafeResult safemultiply(int a, int b){
SafeResult result;
if(a > INT_MAX / b || a < INT_MIN / b){
    result.errorflag  = 1;
    result.value = 0;
}
else{
    result.errorflag = 0;
    result.value = a * b;
}
return result;
}
SafeResult safedivide(int a, int b){
SafeResult result;
if(b == 0){
    result.errorflag = 1;
    result.value = 0;
}
else if(a == INT_MAX && b == -1){
    result.errorflag = 1;
    result.value =  0;    
}
else{
    result.errorflag = 0;
    result.value = a / b;
}
return result;
}
SafeResult safestrtoint(char string[]) {
    SafeResult result;
    result.value = 0;
    result.errorflag = 1;
    int length = strlen(string);
    int negativeflag = 0;
    int start = 0;

    if (string[0] == '-') {
        negativeflag = 1;
        start = 1;
    }

    for (int i = start; i < length; i++) {
        if (string[i] < '0' &&  string[i] > '9') {
            return result;
        }
    }

    for (int i = start; i < length; i++) {
        if ((result.value > (INT_MAX / 10)) || (result.value == (INT_MAX / 10) && (string[i] - '0') > (INT_MAX % 10))) {
            return result;
        }
        result.value = result.value * 10 + (string[i] - '0');
    }

    if (negativeflag) {
        result.value = -result.value;
    }
    result.errorflag = 0;
    return result;
}
