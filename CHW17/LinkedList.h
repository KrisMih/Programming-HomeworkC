#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef unsigned int uint;

typedef enum {
    New,
    Started,
    Finished
} Status;

typedef struct {
    char name[100];
    Status status;
} Task;

typedef Task ListType;

typedef struct Node {
    ListType value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    uint size;
} LinkedList;

LinkedList init();
void pushBack(LinkedList* list, ListType value);
void pushFront(LinkedList* list, ListType value);
void push(LinkedList* list, uint index, ListType value);
ListType popBack(LinkedList* list);
ListType popFront(LinkedList* list);
ListType pop(LinkedList* list, uint index);
Node* getNode(LinkedList* list, uint index);
ListType get(LinkedList* list, uint index);
void set(LinkedList* list, uint index, ListType value);
void release(LinkedList* list);

#endif
