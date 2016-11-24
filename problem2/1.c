#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"

int main(void) {

  double l_arr[3][3] = {
    { 1, 0, 0},
    {-1, 1, 0},
    {-2, 3, 1}
  };
  double b_arr[3] = { 9, -1, 2 };
  Matrix l = MAT_INIT(3, 3, l_arr);
  Vector b = vec_init(3, b_arr);

  Vector y = do_fw_subst(l, b);
  printf("[1]:\n");
  vec_print(y);
  mat_free(l);
  vec_free(b);
  vec_free(y);

  double u_arr[3][3] = {
    { 3,  1, -3},
    { 0, -2, -1},
    { 0,  0,  2}
  };
  double c_arr[3] = { 9, 8, -4 };
  Matrix u = MAT_INIT(3, 3, u_arr);
  Vector c = vec_init(3, c_arr);

  Vector x = do_bw_subst(u, c);
  printf("[2]:\n");
  vec_print(x);
  mat_free(u);
  vec_free(c);
  vec_free(x);

  return 0;
}
