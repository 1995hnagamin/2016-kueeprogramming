#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"

Vector do_fw_subst(Matrix l, Vector b) {
  assert(l.columns == b.size);
  Vector y = vec_copy(b);
  for (size_t i = 0; i < b.size; ++i) {
    for (size_t k = 0; i > 0 && k < i; ++k) {
      y.ptr[i] -= l.ptr[i][k] * y.ptr[k];
    }
  }
  return y;
}

Vector do_back_subst(Matrix u, Vector c) {
  assert(u.columns == c.size);
  size_t const n = c.size;
  Vector x = vec_init_by_const(n, 0);

  size_t i = n;
  while (i != 0) {
    --i;
    Element sum = c.ptr[i];
    for (size_t k = n - 1; k > i; --k) {
      sum -= u.ptr[i][k] * x.ptr[k];
    }
    x.ptr[i] = sum / u.ptr[i][i];
  }

  return x;
}

int main(void) {

  double l_arr[3][3] = {
    { 1, 0, 0},
    {-1, 1, 0},
    {-2, 3, 0}
  };
  double b_arr[3] = { 9, -1, 2 };
  Matrix l = MAT_INIT(3, 3, l_arr);
  Vector b = vec_init(3, b_arr);

  Vector y = do_fw_subst(l, b);
  printf("[1]:\n");
  vec_print(y);
  vec_free(y);

  double u_arr[3][3] = {
    { 3,  1, -3},
    { 0, -2, -1},
    { 0,  0,  2}
  };
  double c_arr[3] = { 9, 8, -4 };
  Matrix u = MAT_INIT(3, 3, u_arr);
  Vector c = vec_init(3, c_arr);

  Vector x = do_back_subst(u, c);
  printf("[2]:\n");
  vec_print(x);
  vec_free(x);

  return 0;
}
