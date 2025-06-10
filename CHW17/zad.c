#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

const char* status_to_string(Status s) {
    switch (s) {
        case New: return "New";
        case Started: return "Started";
        case Finished: return "Finished";
        default: return "Unknown";
    }
}

void add_task(LinkedList* list, const char* name, uint priority) {
    if (priority < 1) priority = 1;
    if (priority > list->size) priority = list->size + 1;

    Task task;
    strncpy(task.name, name, sizeof(task.name) - 1);
    task.name[sizeof(task.name) - 1] = '\0';
    task.status = New;
    push(list, priority - 1, task);
}

void print_tasks(LinkedList* list) {
    if (list->size == 0) {
        printf("There are no tasks.\n");
        return;
    }
    for (uint i = 0; i < list->size; i++) {
        Task task = get(list, i);
        printf("%u. %s - %s\n", i + 1, task.name, status_to_string(task.status));
    }
}

void change_status(LinkedList* list, uint priority, Status status) {
    if (priority < 1 || priority > list->size) {
        printf("Invalid priority!\n");
        return;
    }
    Node* node = getNode(list, priority - 1);
    if (node) {
        node->value.status = status;
        printf("Task \"%s\" status changed to %s.\n", node->value.name, status_to_string(status));
    }
}

void delete_task(LinkedList* list, uint priority) {
    if (priority < 1 || priority > list->size) {
        printf("Invalid priority!\n");
        return;
    }
    Task task = pop(list, priority - 1);
    printf("Task \"%s\" deleted.\n", task.name);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void read_line(char* buffer, size_t size) {
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
    }
}

int main(void) {
    LinkedList list = init();
    char input[128];
    char name[100];
    int choice = 0;
    uint priority;
    int status;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Change Task Status\n");
        printf("3. Delete Task\n");
        printf("4. Print Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        read_line(input, sizeof(input));
        if (scanf(input, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number from 1 to 5.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                read_line(name, sizeof(name));

                printf("Enter priority: ");
                read_line(input, sizeof(input));
                if (scanf(input, "%u", &priority) != 1) {
                    printf("Invalid priority\n");
                    break;
                }
                add_task(&list, name, priority);
                break;

            case 2:
                printf("Enter task priority to change: ");
                read_line(input, sizeof(input));
                if (scanf(input, "%u", &priority) != 1) {
                    printf("Invalid priority.\n");
                    break;
                }

                printf("Enter new status (0 = New, 1 = Started, 2 = Finished): ");
                read_line(input, sizeof(input));
                if (scanf(input, "%d", &status) != 1 || status < 0 || status > 2) {
                    printf("Invalid status.\n");
                    break;
                }

                change_status(&list, priority, (Status)status);
                break;

            case 3:
                printf("Enter task priority to delete: ");
                read_line(input, sizeof(input));
                if (scanf(input, "%u", &priority) != 1) {
                    printf("Invalid priority\n");
                    break;
                }
                delete_task(&list, priority);
                break;

            case 4:
                print_tasks(&list);
                break;

            case 5:
                release(&list);
                printf("Exiting!\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5\n");
                break;
        }
    }

    return 0;
}
