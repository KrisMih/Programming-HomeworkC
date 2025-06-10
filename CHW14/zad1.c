#include <stdio.h>
#include <string.h>

typedef struct {
    char firstName[30];
    char middleName[30];
    char lastName[30];
    char email[50];
    char phone[20];
} Participant;

typedef struct {
    Participant participant;
    int willParticipate;
} ParticipantResponse;

typedef struct {
    char title[100];
    char description[300];
    struct {
        int day;
        int month;
        int year;
        struct {
            int hour;
            int minute;
        } time;
    } date;
    ParticipantResponse responses[100];
    int responseCount;
} Cause;

void printParticipant(Participant p) {
    printf("Име: %s %s %s\n", p.firstName, p.middleName, p.lastName);
    printf("Имейл: %s\n", p.email);
    printf("Телефон: %s\n", p.phone);
}

void printResponse(ParticipantResponse r) {
    printParticipant(r.participant);
    printf("Ще участва: %s\n", r.willParticipate ? "Да" : "Не");
}

void printDate(const Cause *c) {
    printf("Дата: %02d.%02d.%04d %02d:%02d\n",
           c->date.day,
           c->date.month,
           c->date.year,
           c->date.time.hour,
           c->date.time.minute);
}

void printCause(const Cause *c) {
    printf("Каузa: %s\n", c->title);
    printf("Описание: %s\n", c->description);
    printDate(c);
    printf("Участници (%d):\n", c->responseCount);
    for (int i = 0; i < c->responseCount; i++) {
        printf("\nУчастник %d:\n", i + 1);
        printResponse(c->responses[i]);
    }
    printf("\n-------------------------\n");
}

int main() {
    Cause causes[2] = {
        {
            "Залесяване в планината",
            "Каузата цели засаждане на 500 дръвчета в района на Витоша.",
            {15, 4, 2025, {10, 30}},
            {
                {
                    {
                        "Иван", "Георгиев", "Петров",
                        "ivan.petrov@example.com",
                        "0888123456"
                    },
                    1
                },
                {
                    {
                        "Мария", "Иванова", "Симеонова",
                        "maria.simeonova@example.com",
                        "0888987654"
                    },
                    0
                }
            },
            2
        },
        {
            .title = "Хранителна помощ за възрастни",
            .description = "Раздаване на пакети с храна на нуждаещи се възрастни хора.",
            .date = {.day = 20, .month = 4, .year = 2025, .time = {.hour = 14, .minute = 0}},
            .responses = {
                {
                    .participant = {
                        .firstName = "Георги",
                        .middleName = "Николов",
                        .lastName = "Андреев",
                        .email = "georgi.andreev@example.com",
                        .phone = "0888345678"
                    },
                    .willParticipate = 1
                },
                {
                    .participant = {
                        .firstName = "Елена",
                        .middleName = "Стефанова",
                        .lastName = "Павлова",
                        .email = "elena.pavlova@example.com",
                        .phone = "0888765432"
                    },
                    .willParticipate = 1
                }
            },
            .responseCount = 2
        }
    };

    printCause(&causes[0]);
    printCause(&causes[1]);

    return 0;
}
