#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

Employee* createEmployee(const char* name) {
    Employee* employee = (Employee*)malloc(sizeof(Employee));
    if (employee == NULL) {
        perror("Error allocating memory for employee");
        exit(1);
    }
    strncpy(employee->name, name, sizeof(employee->name) - 1);
    employee->name[sizeof(employee->name) - 1] = '\0';
    employee->numberOfSubordinates = 0;
    employee->subordinates = NULL;
    return employee;
}

void addSubordinate(Employee* manager, Employee* subordinate) {
    Employee** newArr = (Employee**)realloc(
        manager->subordinates,
        sizeof(Employee*) * (manager->numberOfSubordinates + 1)
    );
    if (newArr == NULL) {
        perror("Error reallocating memory for subordinates");
        exit(1);
    }
    manager->subordinates = newArr;
    manager->subordinates[manager->numberOfSubordinates] = subordinate;
    manager->numberOfSubordinates++;
}

void printHierarchy(const Employee* employee, int level) {
    if (employee == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) printf("    ");
    printf("%s\n", employee->name);
    for (int i = 0; i < employee->numberOfSubordinates; i++) {
        printHierarchy(employee->subordinates[i], level + 1);
    }
}

void freeEmployee(Employee* employee) {
    if( employee == NULL) {
        return;
    }
    for (int i = 0; i < employee->numberOfSubordinates; i++) {
        freeEmployee(employee->subordinates[i]);
    }
    free(employee->subordinates);
    free(employee);
}

void serializeEmployee(FILE* file, const Employee* employee) {
    if (file == NULL || employee == NULL) {
        return;
    }
    fwrite(employee->name, sizeof(char), 100, file);
    fwrite(&employee->numberOfSubordinates, sizeof(int), 1, file);
    for (int i = 0; i < employee->numberOfSubordinates; i++) {
        serializeEmployee(file, employee->subordinates[i]);
    }
}

Employee* deserializeEmployee(FILE* file) {
    if (file == NULL) {
        return NULL;
    }
    Employee* employee = (Employee*)malloc(sizeof(Employee));
    if (employee == NULL) {
        perror("Error allocating memory");
        return NULL;
    }
    if (fread(employee->name, sizeof(char), 100, file) != 100) {
        free(employee);
        return NULL;
    }
    employee->name[99] = '\0';
    if (fread(&employee->numberOfSubordinates, sizeof(int), 1, file) != 1) {
        free(employee);
        return NULL;
    }
    if (employee->numberOfSubordinates > 0) {
        employee->subordinates = (Employee**)malloc(sizeof(Employee*) * employee->numberOfSubordinates);
        if (employee->subordinates == NULL) {
            perror("Error allocating memory");
            free(employee);
            return NULL;
        }
        for (int i = 0; i < employee->numberOfSubordinates; i++) {
            employee->subordinates[i] = deserializeEmployee(file);
        }
    } else {
        employee->subordinates = NULL;
    }
    return employee;
}