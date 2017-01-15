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
  for (int k = 1; k < 20; ++k) {
    printf("%d %.12lf %.12lf %.12lf %.12lf\n",
        k,
        simpson_integral(func1, 0, 1, k),
        simpson_integral(func2, 0, 1, k),
        simpson_integral(func2, 0, 0.5, k),
        simpson_integral(func2, 0.5, 1, k));
  }
  return 0;
}
