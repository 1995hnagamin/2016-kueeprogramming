#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"

Matrix mat_alloc(size_t r, size_t c) {
  Element *base_ptr = malloc(sizeof(Element) * r * c);
  assert(base_ptr);
  Element **rows = malloc(sizeof(Element*) * r);
  assert(rows);
  for (size_t i = 0; i < r; ++i) {
    rows[i] = base_ptr + i * c;
  }
  Matrix mat;
  mat.rows = r;
  mat.columns = c;
  mat.ptr = rows;
  return mat;
}

void mat_free(Matrix mat) {
  free(mat.ptr[0]);
  free(mat.ptr);
}

Matrix mat_init(size_t r, size_t c, Element const *arr) {
  Matrix mat = mat_alloc(r, c);
  for (size_t i = 0; i < r; ++i) {
    for (size_t j = 0; j < c; ++j) {
      mat.ptr[i][j] = arr[i * c + j];
    }
  }
  return mat;
}

Matrix mat_copy(Matrix m) {
  Matrix dup = MAT_INIT(m.rows, m.columns, m.ptr);
  return dup;
}

Vector vec_alloc(size_t size) {
  Element *ptr = malloc(sizeof(Element) * size);
  assert(ptr);
  Vector vec;
  vec.size = size;
  vec.ptr = ptr;
  return vec;
}

Vector vec_init(size_t size, Element const * src) {
  Vector vec = vec_alloc(size);
  for (size_t i = 0; i < size; ++i) {
    vec.ptr[i] = src[i];
  }
  return vec;
}

Vector vec_init_by_const(size_t size, Element x) {
  Vector vec = vec_alloc(size);
  for (size_t i = 0; i < size; ++i) {
    vec.ptr[i] = x;
  }
  return vec;
}

Vector vec_copy(Vector v) {
  Vector dup = vec_init(v.size, v.ptr);
  return dup;
}

void vec_free(Vector vec) {
  free(vec.ptr);
}

Vector mult_mat_by_vec(Matrix m, Vector v) {
  assert(m.columns == v.size);
  Vector value = vec_alloc(m.rows);
  for (size_t i = 0; i < m.rows; ++i) {
    Element sum = 0;
    for (size_t j = 0; j < m.columns; ++j) {
      sum += m.ptr[i][j] * v.ptr[j];
    }
    value.ptr[i] = sum;
  }
  return value;
}

Matrix mult_mat_by_mat(Matrix a, Matrix b) {
  assert(a.columns == b.rows);
  Matrix value = mat_alloc(a.rows , b.columns);
  for (size_t i = 0; i < a.rows; ++i) {
    for (size_t j = 0; j < a.columns; ++j) {
      value.ptr[i][j] = 0;
    }
  }
  for (size_t i = 0; i < a.rows; ++i) {
    for (size_t k = 0; k < a.columns; ++k) {
      for (size_t j = 0; j < b.columns; ++j) {
        value.ptr[i][j] += a.ptr[i][k] * b.ptr[k][j];
      }
    }
  }
  return value;
}

void mult_mat_by_scalar_dstly(Matrix *a, Element k) {
  for (size_t i = 0; i < a->rows; ++i) {
    for (size_t j = 0; j < a->columns; ++j) {
      a->ptr[i][j] = k * a->ptr[i][j];
    }
  }
}

Matrix mult_mat_by_scalar(Matrix a, Element k) {
  Matrix dup = mat_copy(a);
  mult_mat_by_scalar_dstly(&dup, k);
  return dup;
}

void mult_mat_row_by_scalar_dstly(Matrix *a, size_t i, Element k) {
  for (size_t j = 0; j < a->columns; ++j) {
    a->ptr[i][j] *= k;
  }
}

Matrix mult_mat_row_by_scalar(Matrix a, size_t i, Element k) {
  Matrix dup = mat_copy(a);
  mult_mat_row_by_scalar_dstly(&dup, i, k);
  return dup;
}

void add_mat_rows_dstly(Matrix *a, size_t src,  Element k, size_t dst) {
  assert(src != dst);
  for (size_t j = 0; j < a->columns; ++j) {
    a->ptr[dst][j] += k * a->ptr[src][j];
  }
}

Matrix add_mat_rows(Matrix a, size_t src, Element k, size_t dst) {
  Matrix dup = mat_copy(a);
  add_mat_rows_dstly(&dup, src, k, dst);
  return dup;
}

Matrix transpose_mat(Matrix mat) {
  Matrix tr = mat_alloc(mat.columns, mat.rows);
  for (size_t i = 0; i < mat.rows; ++i) {
    for (size_t j = 0; j < mat.columns; ++j) {
      tr.ptr[j][i] = mat.ptr[i][j];
    }
  }
  return tr;
}

void vec_print(Vector vec) {
  printf("(");
  for (size_t i = 0; i < vec.size; ++i) {
    if (i > 0) {
      printf(", ");
    }
    printf("%.8lf", vec.ptr[i]);
  }
  printf(")\n");
}

void mat_print(Matrix mat) {
  for (size_t i = 0; i < mat.rows; ++i) {
    putchar(i > 0 ? ' ' : '[');
    for (size_t j = 0; j < mat.columns; ++j) {
      if (j > 0) {
        printf(", ");
      }
      printf("%.8lf", mat.ptr[i][j]);
    }
    putchar(i < mat.rows - 1 ? ' ' : ']');
    putchar('\n');
  }
}

