#include <stdio.h>
#define DEBUG
void Sort(int arr[], int n){
    int swap;
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
    for(int i = 3; i < n; i+=3){
            sum = sum + arr[i];
    }
    printf("The sum is:%d\n", sum);
}
void main(){
    int arr[10] = {21, 75, 321, 68, 55, 65, 421, 43512, 7213, 5213};
    #ifdef DEBUG
    Sort(arr, 10);
    for(int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }
    for(int i = 3; i < 10; i+=3){
        printf("The numbers on index divideable by 3 are:%d\n", arr[i]);
    }
    #endif
    
}
