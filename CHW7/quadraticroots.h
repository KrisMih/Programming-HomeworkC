#ifndef QUADRATICROOTS_H_
#define QUADRATICROOTS_H_
typedef struct{
float x1;
float x2;
int norealroots;
} QuadraticRootsResult;
QuadraticRootsResult findroots(double a, double b, double c);
#endif