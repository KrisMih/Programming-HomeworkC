#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

void main(int){
    DynamicArray donator = init(2);
    int choice;
    DynArrType egn;
    while(1){
        printf("\nMenu: \n");
        printf("1. Add a new donator. \n");
        printf("2. Remove a donator. \n");
        printf("3. Print the full list of donators. \n");
        printf("4. Exit. \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter EGN of new donator: ");
            scanf("%d", &egn);
            pushBack(&donator, egn);
        }
        else if(choice == 2){
            printf("Enter an EGN of a donator you want to remove: ");
            scanf("%d", &egn);
            int found = 0;
            for(uint i = 0; i < donator.size; i++){
                if(get(&donator, i) == egn){
                    pop(&donator, i);
                    found = 1;
                    break;
                }
            }
            if(!found){
                printf("EGN ot found in the list!\n");
            }
        }
        else if(choice == 3){
            if(donator.size == 0){
                printf("No donators!\n");
            }
            else{
                printf("\nList of donators's EGNs: \n");
                for(int i = 0; i < donator.size; i++){
                    printf("Donator №%d: %d\n", i + 1, get(&donator, i));
                }
            }
        }
        else if(choice == 4){
            release(&donator);
            printf("Exiting the program...\n");
            break;
        }
        else{
            printf("Invalid choice! Please try again!");
        }
    }
}