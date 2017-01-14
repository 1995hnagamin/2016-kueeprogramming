#ifndef UTIL2_H
#define UTIL2_H

typedef double (*Func)(double);

double f(double);

double trapezoidal_integral(Func, double, double, int);

double simpson_integral(Func, double, double, int);

#endif
