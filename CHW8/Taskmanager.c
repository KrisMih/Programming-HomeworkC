#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processes.h"

int main(){
    int choice, processid;
    char name[30];
    while(1){
        printf("\n Menu: \n");
        printf("1. Create new process\n");
        printf("2. Print a list with all of the processes\n");
        printf("3. Stop a process\n");
        printf("4. Exit\n");
        printf("Choose an option:");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter name of the process: \n");
            scanf("%s", name);
            processid = createnewprocess(name);
            if(processid > 0){
                printf("The process was succesfully created with id: %d\n", processid);
            }
        }
        if(choice == 2){
            printprocesses();
        }
        if(choice == 3){
            printf("Enter id of the process you want to stop\n");
            scanf("%d", &processid);
            stopprocess(processid);
        }
        if(choice == 4){
            printf("Exit of the program");
            break;
        }
        else{
            printf("Not a valid option");
        }
}
}