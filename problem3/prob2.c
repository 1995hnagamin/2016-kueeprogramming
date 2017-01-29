#include <stdio.h>
#include <math.h>
#include "util.h"
#include "euler.h"

int main(void) {
  for (int p = 3; p <= 18; ++p) {
    double const error = calc_max_error(powi(2, p), step_euler);
    printf("%d\t%lf\t%lf\n", p, error, log2(error));
  }
  return 0;
}
