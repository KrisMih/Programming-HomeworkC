#ifndef EMPLYOEE_H
#define EMPLYOEE_H

typedef struct Employee {
    char name[100];
    int numberOfSubordinates;
    struct Employee** subordinates; 
} Employee;

#include <stdio.h>

Employee* createEmployee(const char* name);
void addSubordinate(Employee* manager, Employee* subordinate);
void printHierarchy(const Employee* employee, int level);
void freeEmployee(Employee* employee);
void serializeEmployee(FILE* file, const Employee* employee);
Employee* deserializeEmployee(FILE* file);

#endif 
