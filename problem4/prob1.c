#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"

typedef struct {
  double value;
  Vector vector;
} EigenPair;

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

EigenPair do_power_method(Matrix A, Vector init, double epsilon) {
  Vector x = vec_copy(init);
  normalize_vec_dstly(&x);

  double rayleigh_quo;
  while (1) {
    Vector xnew = mult_mat_by_vec(A, x);
    normalize_vec_dstly(&xnew);

    rayleigh_quo = dot_product(x, xnew) / dot_product(x, x);
    double dissim = dissimilarity(x, xnew);

    vec_free(x);
    x = xnew;

    if (dissim < epsilon) {
      break;
    }
  }

  EigenPair p = { rayleigh_quo, x };
  return p;
}

int main(void) {
  return 0;
}
