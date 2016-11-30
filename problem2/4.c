#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"

Matrix inverse_mat(Matrix A) {
  assert(A.rows == A.columns);
  size_t n = A.rows;

  Matrix ret = mat_alloc(n, n);

  for (size_t j = 0; j < n; ++j) {
    Vector e = vec_init_by_const(n, 0);
    e.ptr[j] = 1;

    Vector x = solve_linear_system(A, e);
    for (size_t i = 0; i < n; ++i) {
      ret.ptr[i][j] = x.ptr[i];
    }
    
    vec_free(x);
    vec_free(e);
  }

  return ret;
}

void get_inverse_of_H(size_t n) {
  printf("n = %zu:\n", n);
  Matrix H = mat_alloc(n, n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      double x = ((double)(i)) - ((double)(j));
      H.ptr[i][j] = pow(0.25, abs(x));
    }
  }

  Matrix Hinv = inverse_mat(H);
  printf("Hinv=\n");
  mat_print(Hinv);
  
  Matrix A = mult_mat_by_mat(H, Hinv);
  printf("H * Hinv =\n");
  mat_print(A);
  A = mult_mat_by_mat(Hinv, H);
  printf("Hinv * H =\n");
  mat_print(A);
  
  mat_free(A);
  mat_free(H);
}

int main(void) {
  get_inverse_of_H(3);
  get_inverse_of_H(6);

  return 0;
}
