#include <math.h>
#include <stdio.h>
#include "mathutil.h"

typedef float (*Func)(float);

float f(float x) {
  return pow(x, 19);
}

float simpson_integral2(Func f, float lower, float upper, int n) {
  float const width = upper - lower;
  float const h = width / (2 * n);
  float sum = 0;
  for (int i = 0; i < n; ++i) {
    float const a = lower + width * i / n;
    float const b = lower + width * (i + 1) / n;
    float const mid = (a + b) / 2;
    sum += (f(a) + 4 * f(mid) + f(b)) * h / 3;
  }
  return sum;
}

void plot(int n) {
  float const answer = 1.0 / 20;
  float const approx = simpson_integral2(f, 0, 1, n);
  printf("%d %.10lf %.10lf %.10lf %.10lf\n",
      n,
      log2(fabs(answer - approx)),
      log2(n),
      approx,
      approx - answer);
}

int main(void) {
  int const limit = 1 << 28;
  printf("# n log_2E log_2n I_c E\n");
  for (int n = 592; n <= limit; n *= 1.1) {
    plot(n);
  }
  printf("\n\n");
  for (int n = 1; n <= limit; n *= 2) {
    plot(n);
  }
  return 0;
}
