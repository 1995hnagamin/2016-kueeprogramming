/* gcc -std=c99 */
#include <math.h>
#include <stdio.h>

#define N 3
typedef double Matrix[N][N];
typedef double Vector[N];

void mat_vec(Matrix  mat, Vector  vec, Vector out) {
  for (size_t i = 0; i < N; ++i) {
    out[i] = 0;
    for (size_t j = 0; j < N; ++j) {
      out[i] += mat[i][j] * vec[j];
    }
  }
}

void mat_mlt(Matrix  in1, Matrix  in2, Matrix out) {
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      out[i][j] = 0;
      for (size_t k = 0; k < N; ++k) {
        out[i][j] += in1[i][k] * in2[k][j];
      }
    }
  }
}

void vec_print(Vector v) {
  printf("(");
  for (size_t i = 0; i < N; ++i) {
    if (i > 0) {
      printf(", ");
    }
    printf("%f", v[i]);
  }
  printf(")\n");
}


void mat_print(Matrix  mat) {
  for (size_t i = 0; i < N; ++i) {
    putchar(i > 0 ? ' ' : '[');
    for (size_t j = 0; j < N; ++j) {
      if (j > 0) {
        printf(", ");
      }
      printf("%f", mat[i][j]);
    }
    putchar(i < N - 1 ? ' ' : ']');
    putchar('\n');
  }
}

int main(void) {
  Matrix  I = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
  };
  Matrix  zero = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
  };
  Matrix  one = {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1},
  };
  Vector  v = { 1, 2, 3 };

  Matrix m_out;
  Vector v_out;

  mat_vec(I, v, v_out); vec_print(v_out);
  mat_vec(zero, v, v_out); vec_print(v_out);
  mat_vec(one, v, v_out); vec_print(v_out);

  mat_mlt(I, zero, m_out); mat_print(m_out);
  mat_mlt(I, one, m_out); mat_print(m_out);
  mat_mlt(one, one, m_out); mat_print(m_out);

  Matrix A = {
    { 1, 4, 7 },
    { 2, 5, 8 },
    { 3, 6, 9 },
  };
  Vector b_1 = { 1, 2, 3 },
         b_2 = { 4, 5, 6 },
         b_3 = { 7, 8, 9 };
  
  mat_vec(A, b_1, v_out); vec_print(v_out);
  mat_vec(A, b_2, v_out); vec_print(v_out);
  mat_vec(A, b_3, v_out); vec_print(v_out);
  mat_mlt(A, A, m_out); mat_print(m_out);
  return 0;
}

