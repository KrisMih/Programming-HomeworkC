#include <stdio.h>
#include <string.h>
#include "processes.h"
Process processes[5];
int processcount = 0;
int nextprocessid(){
    if(processcount >= 5){
        return 0;
    }
    return processcount + 1;
}
int createnewprocess(char name[]){
    if(processcount >= 5){
        printf("Error!  The maximum number of processes is reached! You have to stop one of the processes in order to start a new one");
        return 0;
    }
    int newid = nextprocessid();
    if(newid == 0){
        return 0;
    }
    processes[processcount].id = newid;
    strncpy(processes[processcount].name, name, 30);
    processes[processcount].name[30] = '\0';
    processcount++;
    return newid;
}
void stopprocess(int processid) {
    int found = 0;
    for (int i = 0; i < processcount; i++) {
        if (processes[i].id == processid) {
            for (int j = i; j < processcount - 1; j++) {
                processes[j] = processes[j + 1];
            }
            processcount--;
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Error: Process id not found");
    }
}
void printprocesses(){
    if(processcount == 0){
        printf("There are no active processes\n");
        return;
    }
    for(int i = 0; i < processcount; i++){
        printf("Porcess ID: %d, Name: %s\n", processes[i].id, processes[i].name);
    }
}
