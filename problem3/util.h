#ifndef UTIL_H
#define UTIL_H

#define M_PI 3.14159265358979323846

double square(double);

double powi(int, int);

typedef double State[4];

double x_(State);
double y_(State);
double vx_(State);
double vy_(State);

void calc(State, State);

typedef void StepFunc(double, State, State);

void calc_and_print(StepFunc, int, int);

double calc_max_error(int, StepFunc);

#endif
