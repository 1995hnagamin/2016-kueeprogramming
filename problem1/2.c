#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "matrix.c"

int main(void) {
  double c = 0.5, s = 0.05;
  double const transition_arr[6][6] = {
    {s + (1-s)*(1-c),     (1-s)*c,           0,            0,       0,               0},
    {    (1-s)*(1-c),           s,     (1-s)*c,            0,       0,               0},
    {              0, (1-s)*(1-c),           s,      (1-s)*c,       0,               0},
    {              0,           0, (1-s)*(1-c),            s, (1-s)*c,               0},
    {              0,           0,           0,  (1-s)*(1-c),       s,         (1-s)*c},
    {              0,           0,           0,            0, (1-s)*c, s + (1-s)*(1-c)},
  };
  Matrix T = MAT_INIT(6, 6, transition_arr);
  double const init_pos[6] = { 1, 0, 0, 0, 0, 0 };
  Vector v = vec_init(6, init_pos);
  for (int t = 0; t <= 60; ++t) {
    vec_print(v);
    Vector w = mult_mat_by_vec(T, v);
    vec_free(v);
    v = w;
  }
  return 0;
}
