#include <math.h>
#include <stdio.h>
#include "util2.h"

double func1(double x) {
  return 1.0 / (1 + x * x);
}

double func2(double x) {
  return sqrt(1 - x * x);
}

int main(void) {
  int const k = 10;
  printf("1. %.8lf\n", simpson_integral(func1, 0, 1, k));
  printf("2. %.8lf\n", simpson_integral(func2, 0, 1, k));
  printf("3. %.8lf\n", simpson_integral(func2, 0, 0.5, k));
  printf("4. %.8lf\n", simpson_integral(func2, 0.5, 1, k));
  return 0;
}
