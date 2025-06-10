#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[15 + 1];
    float grade;
} Student;

void read_string(char *string, int size) {
    fgets(string, size, stdin);
    string[strcspn(string, "\n")] = '\0';
}

int main(void) {
    int numberStudents = 0;
    int numberSubjects;

    while (1) {
        printf("Enter number of subjects: ");
        if (scanf("%d", &numberSubjects) != 1 || numberSubjects <= 0) {
            printf("Invalid input! Try again!");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    getchar();

    char **subjects = (char **)malloc(numberSubjects * sizeof(char *));
    for (int i = 0; i < numberSubjects; i++) {
        subjects[i] = (char *)malloc(16 * sizeof(char));
        printf("Enter subject number %d: ", i + 1);
        read_string(subjects[i], 16);
    }

    Student **students = NULL;
    float **grades = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a new student\n");
        printf("2. Print the diary\n");
        printf("3. Exit\n");
        printf("Make your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            students = (Student **)realloc(students, (numberStudents + 1) * sizeof(Student *));
            students[numberStudents] = (Student *)malloc(sizeof(Student));
            grades = (float **)realloc(grades, (numberStudents + 1) * sizeof(float *));
            grades[numberStudents] = (float *)malloc(numberSubjects * sizeof(float));

            printf("Enter student's name: ");
            read_string(students[numberStudents]->name, 16);

            for (int i = 0; i < numberSubjects; i++) {
                printf("Enter grade for %s: ", subjects[i]);
                while (scanf("%f", &grades[numberStudents][i]) != 1 || grades[numberStudents][i] < 2 || grades[numberStudents][i] > 6) {
                    printf("Invalid grade! Enter a grade between 2 and 6: ");
                    while (getchar() != '\n');
                }
                getchar();
            }
            numberStudents++;
            printf("Student added successfully!\n");
        } else if (choice == 2) {
            if (numberStudents == 0) {
                printf("No students added yet!\n");
            } else {
                printf("\n%15s", "");
                for (int i = 0; i < numberSubjects; i++) {
                    printf("%15s", subjects[i]);
                }
                printf("\n");

                for (int i = 0; i < numberStudents; i++) {
                    printf("%15s", students[i]->name);
                    for (int j = 0; j < numberSubjects; j++) {
                        printf("%15.2f", grades[i][j]);
                    }
                    printf("\n");
                }
            }
        } else if (choice == 3) {
            for (int i = 0; i < numberSubjects; i++) {
                free(subjects[i]);
            }
            free(subjects);

            for (int i = 0; i < numberStudents; i++) {
                free(students[i]);
                free(grades[i]);
            }
            free(students);
            free(grades);

            printf("Exiting program. Goodbye!\n");
            return 0;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}