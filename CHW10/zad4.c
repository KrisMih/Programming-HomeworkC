#include <stdio.h>
#define COLUMNS 4
void printTable(int (*arr)[COLUMNS], int rows){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j <COLUMNS; j++){
            printf("%d\t", *(*(arr + i) + j));  
        }
        printf("\n");
    }
}
void main(){
    int arr[][COLUMNS] ={ {1,2,3,4}, {5, 6, 7, 8}, {9, 10, 11, 12} }; 
    int ROWS = sizeof arr/ sizeof (arr[0]);
    printf("The 2D array as a table: \n");
    printTable(arr, ROWS);
}