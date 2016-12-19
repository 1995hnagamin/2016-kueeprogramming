#include <stdio.h>
#include <math.h>
#include "util.h"

int main(void) {
  int const scale = 64;
  double const h = 2 * M_PI / scale;

  double Y[4] = {-1, 0, 0, 1};
  for (int n = 0; n <= scale * 5 ; ++n) {
    double const t = h * n;
    double const error = sqrt(
        square(x_(Y) + cos(t)) + square(y_(Y) - sin(t)));
    printf("%lf\t%lf\t%lf\t%lf\n", t, x_(Y), y_(Y), error);

    double k1[4]; calc(Y, k1);

    double temp[4];
    for (int i = 0; i < 4; ++i) {
      temp[i] = Y[i] + h * k1[i];
    }
    double k2[4]; calc(temp, k2);

    for (int i = 0; i < 4; ++i) {
      Y[i] += (k1[i] + k2[i]) * h / 2;
    }
  }
  return 0;
}
