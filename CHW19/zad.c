#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EGN_SIZE 13

typedef enum {
    EDU_NONE = 0,
    EDU_BASIC = 1,
    EDU_SECONDARY = 2,
    EDU_HIGHER = 3
} Education;

typedef enum {
    STATUS_UNEMPLOYED = 0,
    STATUS_EMPLOYED = 1
} WorkStatus;

typedef enum {
    MARITAL_SINGLE = 0,
    MARITAL_MARRIED = 1
} MaritalStatus;

typedef struct {
    char egn[EGN_SIZE];
    unsigned char name_len;
    char *name;
    unsigned char age;
    unsigned char flags;
} Citizen;

void write_citizen(FILE *f, const Citizen *c) {
    fwrite(c->egn, 1, EGN_SIZE, f);
    fwrite(&c->name_len, 1, 1, f);
    fwrite(c->name, 1, c->name_len, f);
    fwrite(&c->age, 1, 1, f);
    fwrite(&c->flags, 1, 1, f);
}

int read_citizen(FILE *f, Citizen *c) {
    if (fread(c->egn, 1, EGN_SIZE, f) != EGN_SIZE){
        return 0;
    }
    if (fread(&c->name_len, 1, 1, f) != 1){
        return 0;
    }
    c->name = malloc(c->name_len + 1);
    if (!c->name){ 
        return 0;
    }
    if (fread(c->name, 1, c->name_len, f) != c->name_len) {
        free(c->name);
        return 0;
    }
    c->name[c->name_len] = '\0';
    if (fread(&c->age, 1, 1, f) != 1) {
        free(c->name);
        return 0;
    }
    if (fread(&c->flags, 1, 1, f) != 1) {
        free(c->name);
        return 0;
    }
    return 1;
}

void free_citizen(Citizen *c) {
    free(c->name);
}

void print_citizen(const Citizen *c) {
    printf("EGN: %.13s\n", c->egn);
    printf("Name: %s\n", c->name);
    printf("Age: %u\n", c->age);
    printf("Education: ");
    switch (c->flags & 0x03) {
        case EDU_NONE: printf("None"); {
            break;
        }
        case EDU_BASIC: printf("Basic"); {
            break;
        }
        case EDU_SECONDARY: printf("Secondary"); {
            break;
        }
        case EDU_HIGHER: printf("Higher"); {
            break;
        }
    }
    printf("\nWork Status: %s\n", (c->flags & 0x04) ? "Employed" : "Unemployed");
    printf("Marital Status: %s\n", (c->flags & 0x08) ? "Married" : "Single");
    printf("-----------------------\n");
}

unsigned char read_education() {
    int choice;
    printf("Education (0: None, 1: Basic, 2: Secondary, 3: Higher): ");
    scanf("%d", &choice);
    while (choice < 0 || choice > 3) {
        printf("Invalid. Enter again: ");
        scanf("%d", &choice);
    }
    return (unsigned char)choice;
}

unsigned char read_work_status() {
    int choice;
    printf("Work Status (0: Unemployed, 1: Employed): ");
    scanf("%d", &choice);
    while (choice < 0 || choice > 1) {
        printf("Invalid. Enter again: ");
        scanf("%d", &choice);
    }
    return (unsigned char)choice;
}

unsigned char read_marital_status() {
    int choice;
    printf("Marital Status (0: Single, 1: Married): ");
    scanf("%d", &choice);
    while (choice < 0 || choice > 1) {
        printf("Invalid. Enter again: ");
        scanf("%d", &choice);
    }
    return (unsigned char)choice;
}

void add_record(FILE *f) {
    Citizen c;
    char buffer[256];
    printf("Enter EGN (13 digits): ");
    scanf("%13s", c.egn);

    printf("Enter full name (max 255 chars): ");
    getchar();
    fgets(buffer, sizeof(buffer), stdin);
    size_t len = strcspn(buffer, "\n");
    buffer[len] = 0;
    c.name_len = (unsigned char)len;
    c.name = malloc(c.name_len + 1);
    strcpy(c.name, buffer);

    printf("Enter age: ");
    scanf("%hhu", &c.age);

    unsigned char edu = read_education();
    unsigned char work = read_work_status();
    unsigned char marital = read_marital_status();

    c.flags = (edu & 0x03) | ((work & 0x01) << 2) | ((marital & 0x01) << 3);

    fseek(f, 0, SEEK_END);
    write_citizen(f, &c);
    fflush(f);
    free(c.name);

    printf("Record added successfully.\n");
}

int delete_record(FILE *f, const char *target_egn) {
    FILE *temp = tmpfile();
    if (!temp) {
        printf("Error creating temp file.\n");
        return 0;
    }

    rewind(f);
    int found = 0;
    Citizen c;
    while (read_citizen(f, &c)) {
        if (strncmp(c.egn, target_egn, EGN_SIZE) == 0) {
            found = 1;
            free_citizen(&c);
            continue;
        }
        write_citizen(temp, &c);
        free_citizen(&c);
    }

    if (!found) {
        printf("Record with EGN %s not found.\n", target_egn);
        fclose(temp);
        return 0;
    }

    freopen(NULL, "wb+", f);
    rewind(temp);
    Citizen c2;
    while (read_citizen(temp, &c2)) {
        write_citizen(f, &c2);
        free_citizen(&c2);
    }
    fflush(f);
    fclose(temp);
    printf("Record deleted.\n");
    return 1;
}

void print_all(FILE *f) {
    rewind(f);
    Citizen c;
    int count = 0;
    while (read_citizen(f, &c)) {
        print_citizen(&c);
        free_citizen(&c);
        count++;
    }
    if (count == 0) {
        printf("No records found.\n");
    }
}

int main() {
    FILE *file = NULL;
    char filename[260];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Open/Create file\n");
        printf("2. Add record\n");
        printf("3. Delete record by EGN\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Choose option: ");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            if (file) fclose(file);
            printf("Enter filename: ");
            scanf("%259s", filename);
            file = fopen(filename, "rb+");
            if (!file) {
                file = fopen(filename, "wb+");
                if (!file) {
                    printf("Error opening/creating file.\n");
                    continue;
                }
            }
            printf("File '%s' is open.\n", filename);
        } else if (option == 2) {
            if (!file) {
                printf("Open a file first.\n");
                continue;
            }
            add_record(file);
        } else if (option == 3) {
            if (!file) {
                printf("Open a file first.\n");
                continue;
            }
            char del_egn[EGN_SIZE+1];
            printf("Enter EGN to delete: ");
            scanf("%13s", del_egn);
            delete_record(file, del_egn);
        } else if (option == 4) {
            if (!file) {
                printf("Open a file first.\n");
                continue;
            }
            print_all(file);
        } else if (option == 5) {
            if (file) fclose(file);
            break;
        } else {
            printf("Invalid option.\n");
        }
    }
    return 0;
}
