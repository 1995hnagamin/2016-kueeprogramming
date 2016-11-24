#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"

typedef struct {
  Matrix L;
  Matrix U;
} LU_result;

LU_result do_LU_decomposition(Matrix A) {
  size_t const n = A.rows;
  Matrix L = mat_alloc(n, n);
  Matrix U = mat_alloc(n, n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      L.ptr[i][j] = (i == j ? 1 : 0);
      U.ptr[i][j] = 0;
    }
  }

  for (size_t i = 0; i < n; ++i) {

    for (size_t j = 0; j < i; ++j) {
      Element sum = A.ptr[i][j];
      for (size_t k = 0; k < j; ++k) {
        sum -= L.ptr[i][k] * U.ptr[k][j];
      }
      L.ptr[i][j] = sum / U.ptr[j][j];
    }

    for (size_t j = i; j < n; ++j) {
      Element sum = A.ptr[i][j];
      for (size_t k = 0; k < j; ++k) {
        sum -= L.ptr[i][k] * U.ptr[k][j];
      }
      U.ptr[i][j] = sum;
    }

  }
  LU_result res;
  res.L = L, res.U = U;
  return res;
}

void lu_res_free(LU_result res) {
  mat_free(res.L);
  mat_free(res.U);
}

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

  mat_print(A);
  LU_result res = do_LU_decomposition(A);
  printf("\nL = \n");
  mat_print(res.L);
  printf("\nU = \n");
  mat_print(res.U);

  mat_free(AL);
  mat_free(AU);
  mat_free(A);
  lu_res_free(res);

  return 0;
}
