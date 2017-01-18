#include <math.h>
#include <stdio.h>
#include "mathutil.h"
#include "util2.h"

double simpson_integral2(Func f, double lower, double upper, int n) {
  double const width = upper - lower;
  double const h = width / (2 * n);
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    double const a = lower + width * i / n;
    double const b = lower + width * (i + 1) / n;
    double const mid = (a + b) / 2;
    sum += (f(a) + 4 * f(mid) + f(b)) * h / 3;
  }
  return sum;
}

void plot(int n) {
  double const answer = 1.0 / 20;
  double const approx = simpson_integral2(f, 0, 1, n);
  printf("%d %.10lf %.10lf %.10lf %.10lf\n",
      n,
      log2(fabs(answer - approx)),
      log2(n),
      approx,
      approx - answer);
}

int main(void) {
  long long int const limit = 1LL << 33;
  printf("# n log_2E log_2n I_c E\n");
  for (long long int n = 2LL; n <= limit; n *= 2) {
    plot(n);
  }
  printf("\n\n");
  for (int n = 1; n <= limit; n *= 2) {
    plot(n);
  }
  return 0;
}
