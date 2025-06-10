#include <stdio.h>
#include <stdlib.h>

enum WEEKDAY{
    MONDAY = 1,
    TUESDAY = 2,
    WEDNESDAY = 3,
    THURSDAY = 4,
    FRIDAY = 5,
    SATURDAY = 6,
    SUNDAY = 7
};

int main(void){
    int day;
    printf("Enter a day(1-7): ");
    scanf("%d", &day);
    switch(day){
        case MONDAY:
        printf("It's Monday!");
        break;
        case TUESDAY:
        printf("It's Tuesday!");
        break;
        case WEDNESDAY:
        printf("It's Wednesday!");
        break;
        case THURSDAY:
        printf("It's Thursday!");
        break;
        case FRIDAY:
        printf("It's Friday!");
        break;
        case SATURDAY:
        printf("It's Saturday!");
        break;
        case SUNDAY:
        printf("It's Sunday!");
        break;
        default:
        printf("Invalid day!");
        break;
    }
}