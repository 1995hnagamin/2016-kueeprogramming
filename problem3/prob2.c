#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double square(double x) {
  return x * x;
}

double powi(int a, int n) {
  return n == 0 ? 1 : n % 2 == 0 ? powi(a * a, n / 2) : a * powi(a, n - 1);
}

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
