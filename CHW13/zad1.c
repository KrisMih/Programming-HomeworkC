#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
typedef ull (*fptr)(ull,ull);

ull reduce(ull arr[], ull n,fptr ptr, ull start){
    ull result = start;
    for(int i = 0; i < n; i++){
        result = ptr(arr[i], result);
    }
    return result;
}

ull add(ull a, ull b){
    return a + b;
}


int main(void){
    ull arr[3] = {1,2,3};
    printf("%llu",reduce(arr, 3, add, 0));
}