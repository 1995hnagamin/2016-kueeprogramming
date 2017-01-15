#include <math.h>
#include <stdio.h>
#include "mathutil.h"
#include "util2.h"

int main(void) {
  int const limit = 10;
  for (int k = 0; k <= limit; ++k) {
    double const answer = 1.0 / 20;
    double const approx = trapezoidal_integral(f, 0, 1, k);
    printf("%d %.10lf\n", k, log2(fabs(answer - approx)));
  }
  return 0;
}
