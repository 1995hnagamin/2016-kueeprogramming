#include <stdio.h>
#include <math.h>
#include "util.h"

double simulate(int p) {
  int const scale = powi(2, p);
  double const h = 2 * M_PI / scale;

  double maxerror = 0;
  double x = -1, y = 0, vx = 0, vy = 1;
  double const period = 1;
  for (int i = 0; i <= scale * period ; ++i) {
    double const t = h * i;
    double const error = sqrt(square(x + cos(t)) + square(y - sin(t)));
    double dx  = h * vx,
           dy  = h * vy,
           dvx = h * vy,
           dvy = h * -vx;
    x += dx, y += dy, vx += dvx, vy += dvy;
    maxerror = fmax(maxerror, error);
  }

  return maxerror;
}

int main(void) {
  for (int p = 3; p <= 18; ++p) {
    double const error = simulate(p);
    printf("%d\t%lf\n", p, error);
  }
  return 0;
}
