#include <math.h>
#include "util.h"

double square(double x) {
  return x * x;
}

double powi(int a, int n) {
  return n == 0 ? 1 : n % 2 == 0 ? powi(a * a, n / 2) : a * powi(a, n - 1);
}

double x_(State s) { return s[0]; }
double y_(State s) { return s[1]; }
double vx_(State s) { return s[2]; }
double vy_(State s) { return s[3]; }

void calc(State src, State dst) {
  dst[0] = vx_(src); dst[1] = vy_(src);
  dst[2] = vy_(src), dst[3] = -vx_(src);
}

double calc_max_error(int scale, StepFunc step) {
  double const h = 2 * M_PI / scale;

  double maxerror = 0;
  State Y = {-1, 0, 0, 1};
  double const period = 1;
  for (int n = 0; n <= scale * period ; ++n) {
    double const t = h * n;
    double const error = sqrt(
        square(x_(Y) + cos(t)) + square(y_(Y) - sin(t)));

    double temp[4];
    step(h, Y, temp);
    for (int i = 0; i < 4; ++i) {
      Y[i] = temp[i];
    }
    maxerror = fmax(maxerror, error);
  }

  return maxerror;
}

