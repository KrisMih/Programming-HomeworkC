#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H
#include "person.h"
typedef struct{
    Person student[26];
    char clas_name;
    int number;
    Person teacher;
} SchoolClass;
#endif