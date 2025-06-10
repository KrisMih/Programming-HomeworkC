#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList init() {
    LinkedList newList = { .head = NULL, .size = 0 };
    return newList;
}

static Node* createNode(ListType value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void pushFront(LinkedList* list, ListType value) {
    Node* newNode = createNode(value);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Node* getNode(LinkedList* list, uint index) {
    if (index >= list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    Node* current = list->head;
    for (uint i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

void pushBack(LinkedList* list, ListType value) {
    if (list->size == 0) {
        pushFront(list, value);
        return;
    }
    Node* last = getNode(list, list->size - 1);
    Node* newNode = createNode(value);
    last->next = newNode;
    list->size++;
}

void push(LinkedList* list, uint index, ListType value) {
    if (index > list->size) {
        printf("Index out of bounds\n");
        exit(1);
    }
    if (index == 0) {
        pushFront(list, value);
    } else {
        Node* prev = getNode(list, index - 1);
        Node* newNode = createNode(value);
        newNode->next = prev->next;
        prev->next = newNode;
        list->size++;
    }
}

ListType get(LinkedList* list, uint index) {
    return getNode(list, index)->value;
}

void set(LinkedList* list, uint index, ListType value) {
    getNode(list, index)->value = value;
}

ListType popFront(LinkedList* list) {
    if (list->size == 0) {
        printf("List is empty\n");
        exit(1);
    }
    Node* toDelete = list->head;
    ListType val = toDelete->value;
    list->head = toDelete->next;
    free(toDelete);
    list->size--;
    return val;
}

ListType popBack(LinkedList* list) {
    if (list->size == 0) return popFront(list);
    if (list->size == 1) return popFront(list);
    Node* prev = getNode(list, list->size - 2);
    Node* last = prev->next;
    ListType val = last->value;
    free(last);
    prev->next = NULL;
    list->size--;
    return val;
}

ListType pop(LinkedList* list, uint index) {
    if (index == 0) return popFront(list);
    Node* prev = getNode(list, index - 1);
    Node* toDelete = prev->next;
    ListType val = toDelete->value;
    prev->next = toDelete->next;
    free(toDelete);
    list->size--;
    return val;
}

void release(LinkedList* list) {
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}
