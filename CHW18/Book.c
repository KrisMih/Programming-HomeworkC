#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Book.h"

#define FILE_NAME "books.txt"

void loadBooks(LinkedList * list){
    FILE * file = fopen(FILE_NAME, "r");
    if(file == NULL){
        printf("File not found!");
        return;
    }
    LinkedListType tempBook;
    while(fscanf(file, "%s %s %s %d %d",
    tempBook.title, tempBook.author, tempBook.genre, &tempBook.year_of_creation, &tempBook.ISBN) == 5) {
        pushBack(list, tempBook);
    } 
    fclose(file);
}

void saveBooks(LinkedList * list){
    FILE * file = fopen(FILE_NAME, "w");
    if(file == NULL){
        printf("File not found.");
        exit(1);
    }
    Node * currentNode = list->head;
    while(currentNode != NULL){
        LinkedListType book = currentNode->value;
        fprintf(file, "%s %s %s %d %d\n", book.title, book.author, book.genre, book.year_of_creation, book.ISBN);
        currentNode = currentNode->next;    
    }
    fclose(file);
}

void addBook(LinkedList * list){
    LinkedListType book;
    printf("Enter title: ");
    scanf("%s", book.title);
    printf("Enter name of author: ");
    scanf("%s", book.author);
    printf("Enter the genre of the book: ");
    scanf("%s", book.genre);
    printf("Enter the year of creatin of the book: ");
    scanf("%d", &book.year_of_creation);
    printf("Enter the ISBN number of the book: ");
    scanf("%d", &book.ISBN);
    pushBack(list, book);
    printf("Book succesfully added!\n");
}

void listBooks(LinkedList * list){
    if(list->size == 0){
        printf("No books available!\n");
    }
    for(uint i = 0; i < list->size; i++){
        LinkedListType book = get(list, i);
        printf("Title: %s, Author: %s, Genre: %s, Year of creation: %d, ISBN: %d \n", book.title, book.author, book.genre, book.year_of_creation, book.ISBN);
    }
}

void deleteByISBN(LinkedList *list, int isbn) {
    int found = 0;
    for(int i = 0; i < list->size; i++){
        Book book = get(list, i);
        if(book.ISBN == isbn){
            pop(list, i);
            printf("Book with ISBN: %d, succesfuly deleted!\n", isbn);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Book with ISBN: %d, not found!\n", isbn);
    }
}

int main(void){
    LinkedList library = init();
    loadBooks(&library);
    int choice;
    int isbn;
    while(1){
        printf("\nElectronic library:\n");
        printf("1. Add a book\n");
        printf("2. List books\n");
        printf("3. Delete book by ISBN\n");
        printf("4. Save and exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            addBook(&library);
        }
        else if(choice == 2){
            listBooks(&library);
        }
        else if(choice == 3){
            printf("Enter ISBN number to delete: ");
            scanf("%d", &isbn);
            deleteByISBN(&library, isbn);
        }
        else if(choice == 4){
            saveBooks(&library);
            release(&library);
            printf("Exiting\n");
            break;
        }
        else{
            printf("Invalid choice. Exiting the programme with an error!\n");
            exit(1);
        }
    }
}