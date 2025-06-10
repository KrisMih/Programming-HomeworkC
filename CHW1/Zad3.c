#include <stdio.h>

void bubblesort(int arr[], int arrlen);
int sortedevenindexesproduct(int *arr, int arrlen);

int main(void) {
  int array[5] = {1,9,3,2,5};
  bubblesort(array, 5);
  int product = sortedevenindexesproduct(array, 5);
  printf("%d", product);
  return 0;
}

void bubblesort(int arr[], int arrlen) {
  int temp, sorted;
  for (int i = 0; i < arrlen; i++) {
    sorted = 0;
    for (int j = 0; j < arrlen - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        sorted = 1;
      }
    }
    if(sorted == 0){
        break;
    }
  }
}

int sortedevenindexesproduct(int arr[], int arrlen) {
  int product = 1;
  for (int i = 2; i < arrlen; i+=2) {
    product *= arr[i];
  }
  return product;
}