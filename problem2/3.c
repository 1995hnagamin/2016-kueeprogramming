#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"

void aaa(size_t n) {
  printf("n = %zu:\n", n);
  Matrix H = mat_alloc(n, n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      double x = ((double)(i)) - ((double)(j));
      H.ptr[i][j] = pow(0.25, abs(x));
    }
  }
  Vector b = vec_alloc(n);
  for (size_t i = 0; i < n; ++i) {
    double x = ((double)(i));
    b.ptr[i] = 5.0 - pow(4, x - n + 1) - pow(4, -x);
  }

  Vector x = solve_linear_system(H, b);
  vec_print(x);

  mat_free(H);
  vec_free(b);
  vec_free(x);
}

int main(void) {
  aaa(3);
  aaa(6);

  return 0;
}
