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

Vector change_direction(Matrix A, Vector x) {
  Vector xnew = mult_mat_by_vec(A, x);
  normalize_vec_dstly(&xnew);
  return xnew;
}

EigenPair do_power_method(Matrix A, Vector init, double epsilon) {
  Vector x = vec_copy(init);
  normalize_vec_dstly(&x);

  printf("# count R dissim");
  for (size_t i = 0; i < x.size; ++i) {
    printf(" x_%zu", i + 1);
  }
  printf("\n");

  double rayleigh_quo;
  int count = 1;
  while (1) {
    Vector xnew = change_direction(A, x);

    rayleigh_quo = dot_product(x, xnew) / dot_product(x, x);
    double dissim = dissimilarity(x, xnew);

    printf("%d %.8lf %.17lf", count, rayleigh_quo, dissim);
    for (size_t i = 0; i < xnew.size; ++i) {
      printf(" %.8lf", xnew.ptr[i]);
    }
    printf("\n");

    vec_free(x);
    x = xnew;

    if (dissim < epsilon) {
      break;
    }
    ++count;
  }

  EigenPair p = { rayleigh_quo, x };
  return p;
}

int main(void) {
  size_t const n = 6;
  double const A_arr[6][6] = {
    { 2,  3,  4,  5,  6,  7},
    { 3,  8,  9, 10, 11, 12},
    { 4,  9, 13, 14, 15, 16},
    { 5, 10, 14, 17, 18, 19},
    { 6, 11, 15, 18, 20, 21},
    { 7, 12, 16, 19, 21, 22}
  };
  Matrix A = MAT_INIT(6, 6, A_arr);

  Vector u_0 = vec_init_by_const(n, 1);
  normalize_vec_dstly(&u_0);

  EigenPair p = do_power_method(A, u_0, 1e-15);
  fprintf(stderr, "Eigenvalue: %.8lf\n", p.value);
  fprintf(stderr, "Eigenvector: ");
  vec_fprint(stderr, p.vector);

  mat_free(A);
  vec_free(u_0);
  vec_free(p.vector);

  return 0;
}
