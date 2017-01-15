#include <math.h>
#include <stdio.h>
#include "util2.h"

typedef double (*Aprxmtr)(Func, double, double);

double rec_integral(Func f, Aprxmtr apr, int n, double lower, double upper) {
  if (n <= 0) {
    return apr(f, lower, upper);
  } else {
    double mid = (lower + upper) / 2;
    return rec_integral(f, apr, n - 1, lower, mid) +
           rec_integral(f, apr, n - 1, mid, upper);
  }
}

double simpson(Func f, double a, double b) {
  double h = (b - a) / 2,
         mid = (a + b) / 2;
  return (f(a) + 4 * f(mid) + f(b)) / 3 * h;
}

int main(void) {
  int const limit = 25;
  for (int k = 1; k <= limit; ++k) {
    double const answer = 1.0 / 20;
    double const approx = rec_integral(f, simpson, k, 0, 1);
    printf("%d %.10lf\n", k, log2(fabs(answer - approx)));
  }
  return 0;
}
