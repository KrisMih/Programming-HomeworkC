#include <stdio.h>
#include <stdlib.h>

#define CHECK(ptr)\
if(ptr == NULL) {\
printf("Problem with memory allocation!");\ 
exit(1);\
}

void Clean(){
    while(getchar() != '\n');
}

int main(void){
    int num;
    int choice;
    printf("Enter number of grades: ");
    scanf("%d", &num);
    int * grades = (int *)malloc(sizeof(int) * num);
    while(1){
        if(num <= 0){
            printf("Not a valid number of grades! Please try again!\n");
            Clean();
            scanf("%d", &num);
        }
        else{
            break;
        }
    }
    for(int i = 0; i < num; i++){
        while(1){
            printf("Enter grade %d: ", i + 1);
            scanf("%d", &grades[i]);
            if(grades[i] < 0){
                printf("Invalid grade! Enter another one that is 0 or a positive number!");
                scanf("%d", &grades[i]);
            }
            else{
                break;
            }
        }
    }
    while(1){
        printf("\nMenu:\n");
        printf("1. Average grade of student\n");
        printf("2. Add new grade\n");
        printf("3. Delete last grade\n");
        printf("4. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            float sum = 0;
            for(int i = 0; i < num; i++){
                sum += grades[i];
            }
            printf("The average grade of this student is: %f", sum / num);
        }
        else if(choice == 2){
            num++;
            int * temp = (int *)realloc(grades, sizeof(int) * num);
            CHECK(temp);
            grades = temp;
            while(1){
            if(scanf("%d", &grades[num - 1]) != 1 || grades[num - 1] < 0){
                printf("Invalid grade! Try again\n");
                Clean();
            }
            else{
                printf("Succesfully added new grade!\n");
                break;
            }
        }
        }
        else if(choice == 3){
            num--;
            int * temp = (int *)realloc(temp, sizeof(int) * num);
            if(temp != NULL){
                grades = temp;
                printf("Successfully deleted the last grade!\n");
            }
            else{
                printf("No grades were deleted!\n");
            }
        }
        else if(choice == 4){
            CHECK(grades);
        }
        else{
            printf("Invalid choice! Please, try again!\n");
        }
    }
}