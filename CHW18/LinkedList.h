#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Book.h"
typedef Book LinkedListType;
typedef unsigned int uint;

typedef struct Node {
    LinkedListType value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    uint size;
} LinkedList;

LinkedList init();
void pushBack(LinkedList *list, LinkedListType value);
LinkedListType get(LinkedList *list, uint index);
LinkedListType pop(LinkedList *list, uint index);
void release(LinkedList *list);

#endif
