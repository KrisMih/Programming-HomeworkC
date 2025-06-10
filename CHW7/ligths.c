#include <stdio.h>
unsigned char switchon(unsigned char state, int room){
    room -= 1;
    state ^= (1 << room);
    return state;
}
void printstate(unsigned char state){
for(int i = 0; i < 8; i++){
        int room;
        if(state &(1 << i)){
            printf("The lights is on in room:%d\n", i + 1);
        }
    }
}
void main(){
    unsigned char state = 0;
    int room;
    while(1){
        int choice;
        printf("\nMenu:\n");
        printf("1. Switch on lights\n");
        printf("2. Print state of ligths\n");
        printf("3. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
    if(choice == 1){
        printf("Enter room number(1-8)");
        scanf("%d", &room);
        if(room < 1 || room > 8){
            printf("Invalid room number");
        }
        else{
        state = switchon(state, room);
        printf("Ligth switched on in room %d\n", room);
        }
    }
    else if(choice == 2){
        printstate(state);
    }
    else if(choice == 3){
        break;
    }
    else{
        printf("Invalid choice number! Choose in the interval 1 to 3");
    }
    }
}
