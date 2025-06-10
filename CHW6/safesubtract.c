#include <stdio.h>
#include "safeint.h"
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Enter  2 numbers");
        return 1;
    }

    SafeResult result = safestrtoint(argv[1]);
    if (result.errorflag) {
        printf("Problem handling the first number");
        return 1;
    }
    int a = result.value;
    result = safestrtoint(argv[2]);
    if (result.errorflag) {
        printf("Problem handling the second number");
        return 1;
    }
    int b = result.value;

    result = safesubtract(a, b);
    if (result.errorflag) {
        printf("Overflow/Underflow during subtraction");
        return 1;
    }

    printf("The subtraction is: %d\n", result.value);
    return 0;
}
