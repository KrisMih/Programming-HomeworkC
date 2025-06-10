#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node *CreateNode(LinkedListType value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

LinkedList init() {
    LinkedList newList = { .head = NULL, .size = 0 };
    return newList;
}

void pushBack(LinkedList *list, LinkedListType value) {
    Node *newNode = CreateNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    list->size++;
}

static Node *getNode(LinkedList *list, uint index) {
    if (index >= list->size) {
        printf("Index out of bounds.\n");
        exit(1);
    }
    Node *node = list->head;
    for (uint i = 0; i < index; i++)
        node = node->next;
    return node;
}

LinkedListType get(LinkedList *list, uint index) {
    return getNode(list, index)->value;
}

LinkedListType pop(LinkedList *list, uint index) {
    if (index >= list->size) {
        printf("Index out of bounds.\n");
        exit(1);
    }
    Node *toDelete;
    LinkedListType val;

    if (index == 0) {
        toDelete = list->head;
        val = toDelete->value;
        list->head = toDelete->next;
        free(toDelete);
    } else {
        Node *prev = getNode(list, index - 1);
        toDelete = prev->next;
        val = toDelete->value;
        prev->next = toDelete->next;
        free(toDelete);
    }
    list->size--;
    return val;
}

void release(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}
