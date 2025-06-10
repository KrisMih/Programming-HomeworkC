#include <stdio.h>

int compareasc(const void *a, const void *b) {
    const int *pa = (const int *)a;
    const int *pb = (const int *)b;
    if (*pa > *pb){ 
        return 1;
    }
    if (*pa < *pb){
        return -1;
    }
    return 0;
}

int comparedesc(const void *a, const void *b) {
    const int *pa = (const int *)a;
    const int *pb = (const int *)b;
    if (*pa < *pb){
        return 1;
    }
    if (*pa > *pb){
        return -1;
    }
    return 0;
}

void swapelements(void *a, void *b) {
    int *pa = (int *)a;
    int *pb = (int *)b;
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void bubblesort(void *array, size_t n, int (*compare)(const void *, const void *), void (*swapelements)(void *, void *)) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (compare((char *)array + j * sizeof(int), (char *)array + (j + 1) * sizeof(int)) > 0) {
                swapelements((char *)array + j * sizeof(int), (char *)array + (j + 1) * sizeof(int));
            }
        }
    }
}

void printArray(int arr[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int array1[] = {9, 3, 5, 1, 4, 8};
    int array2[] = {9, 3, 5, 1, 4, 8};
    size_t n = sizeof(array1) / sizeof(array1[0]);
    printf("Array before ascending sort:\n");
    printArray(array1, n);
    bubblesort(array1, n, compareasc, swapelements);
    printf("Array after ascending sort:\n");
    printArray(array1, n);
    printf("\nArray before descending sort:\n");
    printArray(array2, n);
    bubblesort(array2, n, comparedesc, swapelements);
    printf("Array after descending sort:\n");
    printArray(array2, n);
}

