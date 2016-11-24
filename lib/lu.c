#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"

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

Vector do_bw_subst(Matrix u, Vector c) {
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

Vector solve_linear_system(Matrix A, Vector b) {
  LU_result res = do_LU_decomposition(A);
  Vector Ux = do_fw_subst(res.L, b);
  Vector x = do_bw_subst(res.U, Ux);
  vec_free(Ux);
  return x;
}
