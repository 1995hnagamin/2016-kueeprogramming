#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double square(double x) {
  return x * x;
}

int main(void) {
  int const scale = 64;
  double const h = 2 * M_PI / scale;

  double x = -1, y = 0, vx = 0, vy = 1;
  double const period = 5;
  for (int i = 0; i <= scale * period ; ++i) {
    double const t = h * i;
    double const error = sqrt(square(x + cos(t)) + square(y - sin(t)));
    printf("%lf\t%lf\t%lf\t%lf\n", t, x, y, error);
    double dx  = h * vx,
           dy  = h * vy,
           dvx = h * vy,
           dvy = h * -vx;
    x += dx, y += dy, vx += dvx, vy += dvy;
  }
  return 0;
}
