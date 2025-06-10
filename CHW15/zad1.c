#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char firstname[50];
    char middlename[50];
    char lastname[50];
    char email[100];
    char phone[20];
} Participant;

typedef struct {
    Participant participant;
    bool willParticipate;
} Answer;

struct {
    int day;
    int month;
    int year;
    struct {
        int hour;
        int minute;
    } time;
} typedef Date;

typedef struct {
    char title[100];
    char description[200];
    Date date;
    Answer answers[100];
    int answerCount;
} Cause;

void printParticipant(Participant p) {
    printf("Name: %s %s %s\n", p.firstname, p.middlename, p.lastname);
    printf("Email: %s\n", p.email);
    printf("Phone: %s\n", p.phone);
}

void printAnswer(Answer a) {
    printParticipant(a.participant);
    printf("Participating: %s\n", a.willParticipate ? "Yes" : "No");
}

void printDate(Date d) {
    printf("Date: %02d/%02d/%04d %02d:%02d\n", d.day, d.month, d.year, d.time.hour, d.time.minute);
}

void printCause(Cause c) {
    printf("Title: %s\n", c.title);
    printf("Description: %s\n", c.description);
    printDate(c.date);
    printf("Participants:\n");
    for (int i = 0; i < c.answerCount; i++) {
        printf("--- Participant %d ---\n", i + 1);
        printAnswer(c.answers[i]);
    }
}

int main() {
    Cause causes[2] = {
        {
            .title = "Tree Planting",
            .description = "Planting trees in the local park.",
            .date = {25, 5, 2025, {10, 30}},
            .answers = {
                {{ "John", "A.", "Doe", "john@example.com", "1234567890" }, true},
                {{ "Jane", "B.", "Smith", "jane@example.com", "0987654321" }, false}
            },
            .answerCount = 2
        },
        {
            .title = "Beach Cleanup",
            .description = "Cleaning the beach area.",
            .date = {10, 6, 2025, {9, 0}},
            .answers = {
                {{ "Alice", "C.", "Johnson", "alice@example.com", "1112223333" }, true},
                {{ "Bob", "D.", "Brown", "bob@example.com", "4445556666" }, true}
            },
            .answerCount = 2
        }
    };

    for (int i = 0; i < 2; i++) {
        printf("=== Cause %d ===\n", i + 1);
        printCause(causes[i]);
        printf("\n");
    }

    return 0;
}

