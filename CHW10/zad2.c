#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                swap(arr + j, arr + j + 1);
            }
        }
    }
}    

void printarr(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
}
void main(){
    int arr[] = {10, 25, 34, 3, 1, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sort: \n");
    printarr(arr,n);
    BubbleSort(arr, n);
    printf("Array after sort: \n");
    printarr(arr,n);
}