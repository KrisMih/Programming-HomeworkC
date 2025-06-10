#include <stdio.h>
#include "person.h"
#include "schoolclass.h"
#include "schoolroom.h"
typedef struct {
    SchoolClass school_classes[20];
    SchoolRoom school_rooms[10];
} School;
void main(){
    School school;
    SchoolClass class1 = {
        .student = {
            {"Aleksnadar", "Viktorov", "Ivanov", 2009},
            {"Vogil", "Preslavov", "Dimitrov", 2011}
        },
        .clas_name = 'B',
        .number = 1,
        .teacher = {"Preslav", "Mihailov", "Jordanov", 1968}
    };
    school.school_classes[0] = class1;
    SchoolRoom room1 = {
        .number = 1922,
        .people_in_room = {
            {"Dobromir", "Ivanov", "Jelev", 2010},
            {"Viktor", "Viktorov", "Vasilev", 2009}
        }
    };
    
}