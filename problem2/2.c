#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"

int main(void) {
  double AL_arr[3][3] = {
    { 1, 0, 0},
    {-1, 1, 0},
    {-2, 3, 1}
  };
  Matrix AL = MAT_INIT(3, 3, AL_arr);
  double AU_arr[3][3] = {
    {3,  1, -3},
    {0, -2, -1},
    {0,  0,  2}
  };
  Matrix AU = MAT_INIT(3, 3, AU_arr);
  Matrix A = mult_mat_by_mat(AL, AU);
  mat_free(AL);
  mat_free(AU);

  mat_print(A);
  LU_result res = do_LU_decomposition(A);
  printf("\nL = \n");
  mat_print(res.L);
  printf("\nU = \n");
  mat_print(res.U);

  double b_arr[3] = {9, -1, 2}; 
  Vector b = vec_init(3, b_arr);
  Vector x = solve_linear_system(A, b);
  printf("\nx = \n");
  vec_print(x);

  vec_free(b);
  vec_free(x);
  mat_free(A);
  lu_res_free(res);

  return 0;
}
