#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.h"

void vec_print_csv(Vector vec) {
  for (size_t i = 0; i < vec.size; ++i) {
    printf("%.8lf,", vec.ptr[i]);
  }
  double sum = 0;
  for (size_t i = 0; i < vec.size; ++i) {
      sum += vec.ptr[i];
  }
  printf("%.9lf\n", sum);
}

int simulate(double c, double s) {
  double const transition_arr[6][6] = {
    {s + (1-s)*(1-c), (1-s)*(1-c),           0,            0,           0,               0},
    {        (1-s)*c,           s, (1-s)*(1-c),            0,           0,               0},
    {              0,     (1-s)*c,           s,      (1-s)*c,           0,               0},
    {              0,           0,     (1-s)*c,            s,     (1-s)*c,               0},
    {              0,           0,           0,  (1-s)*(1-c),           s,         (1-s)*c},
    {              0,           0,           0,            0, (1-s)*(1-c), s + (1-s)*(1-c)},
  };
  Matrix T = MAT_INIT(6, 6, transition_arr);
  double const init_pos[6] = { 1, 0, 0, 0, 0, 0 };
  Vector v = vec_init(6, init_pos);
  printf("s=%lf,c=%lf\n", s, c);

  printf("t,");
  for (int i = 0; i < 6; ++i) {
    printf("%d,", i);
  }
  printf("sum\n");

  for (int t = 0; t <= 60; ++t) {
    printf("%d,", t);
    vec_print_csv(v);
    Vector w = mult_mat_by_vec(T, v);
    vec_free(v);
    v = w;
  }
  mat_free(T);
  vec_free(v);
  return 0;
}

int main(void) {
  simulate(0.5, 0.05);
  simulate(0.5, 0.15);
  simulate(0.5, 0.5);
  simulate(0.7, 0.15);
  simulate(0.5, 0.15);
  simulate(0.45,0.15);
  return 0;
}
