#include <stdio.h>
#include <math.h>

double square(double x) {
  return x * x;
}

typedef struct {
  double arr[4];
} State;

double state_x(State s)  { return s.arr[0]; }
double state_y(State s)  { return s.arr[1]; }
double state_vx(State s) { return s.arr[2]; }
double state_vy(State s) { return s.arr[3]; }

State state_add(State s1, State s2) {
  State val;
  for (int i = 0; i < 4; ++i) {
    val.arr[i] = s1.arr[i] + s2.arr[i];
  }
  return val;
}

State state_mult(double k, State s) {
  State val;
  for (int i = 0; i < 4; ++i) {
    val.arr[i] = k * s.arr[i];
  }
  return val;
}

State f(State s) {
  State ds = {{
    state_vx(s),
    state_vy(s),
    state_vy(s),
    -state_vx(s)
  }};
  return ds;
}

void state_print(State s) {
  printf("%lf, %lf, %lf, %lf\n",
      state_x(s), state_y(s), state_vx(s), state_vy(s));
}

int main(void) {
  int const scale = 64;
  double const PI = acos(-1);
  double const h = 2 * PI / scale;

  State s = {{ -1, 0, 0, 1 }};
  for (int i = 0; i < scale * 10; ++i) {
    double const t = h * i;
    double const error = sqrt(
        square(state_x(s) + cos(t)) + square(state_y(s) - sin(t)));
    printf("%lf\t%lf\t%lf\t%lf\n", t, state_x(s), state_y(s), error);
    State k1 = f(s);
    State k2 = f(state_add(s, state_mult(h, k1)));
    s = state_add(s, state_mult(h / 2, state_add(k1, k2)));
    printf("t = %lf\n", t);
    state_print(k1); state_print(k2); state_print(s);
  }
  return 0;
}
