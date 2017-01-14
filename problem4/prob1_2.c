#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"
#include "jacobi.h"

int main(void) {
  double const A_arr[6][6] = {
    { 2,  3,  4,  5,  6,  7},
    { 3,  8,  9, 10, 11, 12},
    { 4,  9, 13, 14, 15, 16},
    { 5, 10, 14, 17, 18, 19},
    { 6, 11, 15, 18, 20, 21},
    { 7, 12, 16, 19, 21, 22}
  };
  Matrix A = MAT_INIT(6, 6, A_arr);

  do_jacobi_method(A);

  mat_free(A);
  return 0;
}
