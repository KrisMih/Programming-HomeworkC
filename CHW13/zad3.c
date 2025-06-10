#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[16];
    int class_number;
    double average_grade;
}student;

int main(void){
    int choice;
    int number_of_students = 0;
    student * students = NULL;
    while(1){
        printf("\nMenu: \n");
        printf("1. Add a student\n");
        printf("2. Print all students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            students = students = realloc(students, sizeof(student) * (number_of_students + 1));
            if(!students){
                printf("Memory allocation failed!\n");
                exit(1);
            }
            printf("Enter name of student: \n");
            while((getchar()) != '\n');
            fgets(students[number_of_students].name, sizeof(students[number_of_students].name), stdin);
            printf("Enter number in class: \n");
            scanf("%d", &students[number_of_students].class_number);
            printf("Enter average grade of student: \n");
            scanf("%lf", &students[number_of_students].average_grade);
            number_of_students++;
        }
        else if(choice == 2){
            for(int i = 0; i < number_of_students; i++){
                printf("Name of student: %s\n", students[i].name);
                printf("Number of student: %d\n", students[i].class_number);
                printf("Average grade of student: %lf\n", students[i].average_grade);
            }
        }
        else if(choice == 3){
            free(students);
            break;
        }
        else{
            printf("Invalid choice! Please try again!\n");
        }
    }
}