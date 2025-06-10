#include <stdio.h>
void BubbleSort(int arr[], int n){
    int swap;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }
}
void InsertionSort(int arr[], int n){
    for(int  i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while( j >= 0 && key < arr[j+1]){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
void SelectionSort(int arr[], int n){
    for(int i = 0; i < n - 1;i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;    
    }
}
void ReverseSort(int arr[], int n){
    int start = 0; 
    int end = n - 1;
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void main(){
    int arr[5] = {1, 34, 41, 23, 24};
    #ifdef _WIN32
    BubbleSort(arr, 5);
    #elif __linux__
    SelectionSort(arr, 5);
    #elif __APPLE__
    InsertionSort(arr, 5);
    #else
    ReverseSort(arr, 5);
    #endif
}