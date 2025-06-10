#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char firstname[50];
    struct Node* father;
    struct Node* mother;
    struct Node* marriedto;
} Node;

void printFamilyMember(Node* person) {
    if (person == NULL) {
        return;
    }
    printf("Name: %s\n", person->firstname);
    if (person->father != NULL) {
        printf("Father: %s\n", person->father->firstname);
    } else {
        printf("Father: Unknown\n");
    }
    if (person->mother != NULL) {
        printf("Mother: %s\n", person->mother->firstname);
    } else {
        printf("Mother: Unknown\n");
    }
    if (person->marriedto != NULL) {
        printf("Married to: %s\n", person->marriedto->firstname);
    } else {
        printf("Married to: Not married\n");
    }
    printf("\n");
}

int main() {
    Node grandfather = {"George", NULL, NULL, NULL};
    Node grandmother = {"Mary", NULL, NULL, NULL};
    Node father = {"John", &grandfather, &grandmother, NULL};
    Node mother = {"Anna", NULL, NULL, NULL};
    Node child = {"Michael", &father, &mother, NULL};

    father.marriedto = &mother;
    mother.marriedto = &father;

    printFamilyMember(&grandfather);
    printFamilyMember(&grandmother);
    printFamilyMember(&father);
    printFamilyMember(&mother);
    printFamilyMember(&child);

    return 0;
}
