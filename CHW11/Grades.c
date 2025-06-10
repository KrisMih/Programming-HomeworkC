#include <stdio.h>
#include <stdlib.h>

#define CHECK(ptr) \
    if(ptr == NULL){ \
        printf("Memory allocation failed\n"); \
        exit(1); \
    }

void main(){
    int num;
    printf("Enter number of grades: ");
    scanf("%d", &num);

    int *grades = (int *)malloc(num * sizeof(int));
    CHECK(grades);

    for(int i = 0; i < num; i++){
        printf("Enter grade %d: ", i+1);
        scanf("%d", &grades[i]);
        if(grades[i] < 0){
            printf("Invalid grade\n");
            i--;
        }
    }

    int choice;
    while(1){
        printf("1. Get average grades of student\n");
        printf("2. Add new grade\n");
        printf("3. Delete last grade\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            float sum = 0;
            for(int i = 0; i < num; i++){
                sum += grades[i];
            }
            printf("Average grade of this student is: %f\n", sum/num);
        }
        else if(choice == 2){
            num++;
            grades = (int *)realloc(grades, num * sizeof(int));
            CHECK(grades);
            printf("Enter new grade: ");
            scanf("%d", &grades[num-1]);
            if(grades[num-1] < 0){
                printf("Invalid grade\n");
                num--;
            }
        }
        else if(choice == 3){
            if(num > 0) {
                num--;
                grades = (int *)realloc(grades, num * sizeof(int));
                CHECK(grades);
            } else {
                printf("No grades to delete\n");
            }
        }
        else if(choice == 4){
            free(grades);
            exit(0);
        }
        else{
            printf("Invalid choice\n");
        }
    }
}
