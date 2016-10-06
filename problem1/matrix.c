#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

typedef double Element;

#define N 4

typedef struct {
  size_t row;
  size_t column;
  Element *ptr;
} Matrix;

Matrix mat_alloc(size_t m, size_t n) {
  Element *ptr = (Element*)malloc(sizeof(Element) * m * n);
  assert(ptr);
  Matrix mat = { m, n, ptr };
  return mat;
}

void mat_free(Matrix mat) {
  free(mat.ptr);
}

Matrix mat_init(size_t m, size_t n, Element const **arr) {
  Matrix mat = mat_alloc(m, n);
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      mat.ptr[i * m + j] = arr[i][j];
    }
  }
  return mat;
}

int main() {
  Element mat_v[4][4] = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 }
  };
  Matrix mat = mat_init(N, N, mat_v);
  return 0;
}
