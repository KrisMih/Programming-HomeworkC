#ifndef BOOK_H
#define BOOK_H
typedef struct{
    char title[100];
    char author[100];
    char genre[50];
    int year_of_creation;
    int ISBN;
}Book;
#endif