#include <stdio.h>
#include <math.h>
#include "util.h"
#include "runge_kutta.h"

int main(void) {
  int const scale = 64;
  double const PI = acos(-1);
  double const h = 2 * PI / scale;

  State Y = {-1, 0, 0, 1};
  for (int n = 0; n <= scale * 5 ; ++n) {
    double const t = h * n;
    double const error = sqrt(
        square(x_(Y) + cos(t)) + square(y_(Y) - sin(t)));
    printf("%lf\t%lf\t%lf\t%lf\n", t, x_(Y), y_(Y), error);

    double temp[4];
    step_runge_kutta(h, Y, temp);
    for (int i = 0; i < 4; ++i) {
      Y[i] = temp[i];
    }
  }
  return 0;
}
