#include <stdio.h>
#include <math.h>
#include "quadraticroots.h"
QuadraticRootsResult findroots(double a, double b, double c){
QuadraticRootsResult result;
result.norealroots = 0;
double Discriminant;
Discriminant = (b * b) - (4 * a * c);
if(Discriminant < 0){
    result.norealroots = 1;
    return result;
}
Discriminant = sqrtl(Discriminant);
result.x1 = (-b + Discriminant) / (2 * a);
result.x2 = (-b - Discriminant) / (2 * a);
return result;
}
