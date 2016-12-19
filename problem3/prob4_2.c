#include <stdio.h>
#include <math.h>
#include "util.h"
#include "runge_kutta.h"

int main(void) {
  for (int p = 3; p <= 18; ++p) {
    double const error = calc_max_error(powi(2, p), step_runge_kutta);
    printf("%d\t%.18lf\n", p, error);
  }
  return 0;
}
