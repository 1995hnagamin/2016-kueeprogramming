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

