#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

typedef double Element;

typedef struct {
  size_t rows;
  size_t columns;
  Element **ptr;
} Matrix;

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
#define MAT_INIT(m, n, arr) mat_init(m, n, &(arr[0][0]))

typedef struct {
  size_t size;
  Element *ptr;
} Vector;

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

Vector vec_free(Vector vec) {
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
    for (size_t j = 0; j < b.columns; ++j) {
      Element sum = 0;
      for (size_t k = 0; k < a.columns; ++k) {
        sum += a.ptr[i][k] * b.ptr[k][j];
      }
      value.ptr[i][j] = sum;
    }
  }
  return value;
}

void mat_print(Matrix mat) {
  for (size_t i = 0; i < mat.rows; ++i) {
    putchar(i > 0 ? ' ' : '[');
    for (size_t j = 0; j < mat.columns; ++j) {
      if (j > 0) {
        printf(", ");
      }
      printf("%f", mat.ptr[i][j]);
    }
    putchar(i < mat.rows - 1 ? ' ' : ']');
    putchar('\n');
  }
}

int main() {
  Element mat_v[4][5] = {
    { 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10 },
    { 11, 12, 13, 14, 15 },
    { 16, 17, 18, 19, 20 },
  };
  Element mat_w[5][3] = {
    {  1,  2,  3 },
    {  4,  5,  6 },
    {  7,  8,  9 },
    { 10, 11, 12 },
    { 13, 14, 15 },
  };
  Matrix v = MAT_INIT(4, 5, mat_v);
  mat_print(v);
  Matrix w = MAT_INIT(5, 3, mat_w);
  mat_print(w);
  Matrix mat = mult_mat_by_mat(v, w);
  printf("%zu x %zu\n", mat.rows, mat.columns);
  mat_print(mat);
  mat_free(mat);
  return 0;
}
