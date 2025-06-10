#include <stdio.h>
#include <math.h>
#include "quadraticroots.h"
void main(){
    QuadraticRootsResult result = findroots(1, 2, 3);
    if(result.norealroots){
        printf("No real roots!\n");
    }
    else{
        printf("x1 = %lf x2 = %lf\n", result.x1, result.x2);
    }
    QuadraticRootsResult result1 = findroots(1.2, 1.3, 1.4);
    if(result1.norealroots){
        printf("No real roots!\n");
    }
    else{
        printf("x1 = %lf x2 = %lf\n", result1.x1, result1.x2);
    }
    QuadraticRootsResult result2 = findroots(1.2412412321521, 2.21344213141, 2143.2142151321);
    if(result2.norealroots){
        printf("No real roots!\n");
    }
    else{
        printf("x1 = %lf x2 = %lf\n", result2.x1, result2.x2);
    }
}