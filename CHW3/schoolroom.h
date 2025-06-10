#ifndef SCHOOLROOM_H
#define SCHOOLROOM_H
#include "person.h"
typedef struct{
    int number;
    Person people_in_room[50];
} SchoolRoom;
#endif