#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "lu.h"
#include "jacobi.h"

typedef struct {
  size_t p, q;
  double value;
} MaxElem;

static MaxElem max_offdiagonal_elem(Matrix A) {
  assert(A.rows == A.columns);
  size_t const n = A.rows;

  MaxElem ret = { 0, 0, 0 };
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      if (i == j) { continue; }
      if (fabs(A.ptr[i][j]) > ret.value) {
        ret.value = fabs(A.ptr[i][j]),
        ret.p = i,
        ret.q = j;
      }
    }
  }
  return ret;
}

void do_jacobi_method(Matrix mat) {
  Matrix A = mat_copy(mat);
  double const epsilon = 1e-8;
  size_t const n = A.rows;

  Matrix U = mat_alloc(n, n);
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      U.ptr[i][j] = (i == j ? 1 : 0);
    }
  }

  int count = 1;
  for (MaxElem m = max_offdiagonal_elem(A); m.value > epsilon; m = max_offdiagonal_elem(A)) {
    Matrix P = mat_alloc(n, n);
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        P.ptr[i][j] = (i == j ? 1 : 0);
      }
    }
    size_t const p = m.p, q = m.q;
    double const tan2theta = -2 * A.ptr[p][q] / (A.ptr[p][p] - A.ptr[q][q]);
    double const theta = atan(tan2theta) / 2;
    P.ptr[p][p] = P.ptr[q][q] = cos(theta);
    P.ptr[p][q] = sin(theta), P.ptr[q][p] = -sin(theta);

    Matrix Pt = transpose_mat(P);
    mult_mat_by_mat_from_left(Pt, &A);
    mult_mat_by_mat_from_right(&A, P);
    mult_mat_by_mat_from_right(&U, P);

    mat_free(P);
    mat_free(Pt);
    printf("count:%d p:%zu q:%zu max_a:%.10lf\n", count, m.p, m.q, m.value);
    printf("A = ");
    mat_print(A);
    printf("U = ");
    mat_print(U);
    ++count;
  }

  Matrix Ut = transpose_mat(U);
  Matrix I = mult_mat_by_mat(U, Ut);
  mat_print(I);


  mult_mat_by_mat_from_left(U, &A);
  mult_mat_by_mat_from_right(&A, Ut);
  mat_print(A);


  mat_free(A);
  mat_free(U);
  mat_free(Ut);
  mat_free(I);
}
