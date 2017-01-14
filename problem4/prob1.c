#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"

double dissimilarity(Vector numer, Vector denom) {
  assert(numer.size == denom.size);
  size_t const n = numer.size;

  double r_min, r_max; r_min = r_max = numer.ptr[0] / denom.ptr[0];
  for (size_t i = 1; i < n; ++i) {
    double const r = numer.ptr[i] / denom.ptr[i];
    r_min = fmin(r_min, r), r_max = fmax(r_max, r);
  }
  return fabs(r_max - r_min);
}

int main(void) {
  return 0;
}
