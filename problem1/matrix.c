#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

typedef double Element;

typedef struct {
  size_t row;
  size_t column;
  Element **ptr;
} Matrix;

Matrix mat_alloc(size_t m, size_t n) {
  Element *base_ptr = malloc(sizeof(Element) * m * n);
  assert(base_ptr);
  Element **rows = malloc(sizeof(Element*) * m);
  assert(rows);
  for (size_t i = 0; i < m; ++i) {
    rows[i] = base_ptr + i * m;
  }
  Matrix mat = { m, n, rows };
  return mat;
}

void mat_free(Matrix mat) {
  free(mat.ptr[0]);
  free(mat.ptr);
}

Matrix mat_init(size_t m, size_t n, Element const *arr) {
  Matrix mat = mat_alloc(m, n);
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      mat.ptr[i][j] = arr[i * m + j];
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
  Vector vec = { size, ptr };
  return vec;
}

Vector vec_free(Vector vec) {
  free(vec.ptr);
}



Vector mult_mat_by_vec(Matrix m, Vector v) {
  assert(m.column == v.size);
  Vector value = vec_alloc(v.size);
  for (size_t i = 0; i < m.row; ++i) {
    Element sum = 0;
    for (size_t j = 0; j < m.column; ++j) {
      sum += m.ptr[i][j] * v.ptr[j];
    }
    value.ptr[i] = sum;
  }
  return value;
}

Matrix mult_mat_by_mat(Matrix a, Matrix b) {
  assert(a.column == b.row);
  Matrix value = mat_alloc(a.row , b.column);
  for (size_t i = 0; i < a.row; ++i) {
    for (size_t j = 0; j < b.column; ++j) {
      Element sum = 0;
      for (size_t k = 0; k < a.column; ++k) {
        sum += a.ptr[i][k] * b.ptr[k][j];
      }
      value.ptr[i][j] = sum;
    }
  }
  return value;
}

void mat_print(Matrix mat) {
  for (size_t i = 0; i < mat.row; ++i) {
    putchar(i > 0 ? ' ' : '[');
    for (size_t j = 0; j < mat.column; ++j) {
      if (j > 0) {
        printf(", ");
      }
      printf("%f", mat.ptr[i][j]);
    }
    putchar(i < mat.column - 1 ? ' ' : ']');
    putchar('\n');
  }
}

int main() {
  Element mat_v[5][5] = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 },
    { 13, 14, 15, 16 }
  };
  Matrix mat = MAT_INIT(5, 5, mat_v);
  print_mat(mat);
  return 0;
}
