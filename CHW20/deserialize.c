#include "employee.h"
#include <stdio.h>

int main() {
    FILE* file = fopen("employees.bin", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Employee* root = deserializeEmployee(file);
    fclose(file);

    if (root == NULL) {
        printf("Error while deserializing!\n");
        return 1;
    }
    printHierarchy(root, 0);
    freeEmployee(root);
    return 0;
}