#include <math.h>
#include "mathutil.h"
#include "util2.h"

double f(double x) {
  return pow(x, 19);
}

double trapezoidal_integral(Func f, double lower, double upper, int k) {
  int const n = powi(2, k);
  double const width = upper - lower;
  double const h = width / n;
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    double const a = lower + width * i / n;
    double const b = lower + width * (i + 1) / n;
    sum += (f(a) + f(b)) * h / 2;
  }
  return sum;
}
