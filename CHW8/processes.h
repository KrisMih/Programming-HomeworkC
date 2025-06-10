#ifndef PROCESSES_H_
#define PROCESSES_H_
typedef struct{
int id;
char name[30];
} Process;
extern Process processes[5];
extern int processcount;
int nextprocessid();
int createnewprocess(char name[]);
void stopprocess(int processid);
void printprocesses();
#endif