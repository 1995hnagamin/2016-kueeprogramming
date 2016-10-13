#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef double (*Func)(double);

typedef struct {
  bool conversed;
  double answer;
} Result;

Result iterate(Func f, double init, double epsilon, int limit) {
  double x = init;
  double y = f(x);
  int iter;
  for (iter = 0; fabs(x - y) >= epsilon && iter < limit; ++iter) {
    x = y;
    y = f(y);
  }
  if (iter < limit) {
    Result res = { true, y };
    return res;
  } else {
    Result res = { false, 0 };
    return res;
  }
}

void newton(Func f, double init) {
  Result res = iterate(f, init, 1e-9, 1000);
  if (res.conversed) {
    printf("Answer: %f\n", res.answer);
  } else {
    printf("Failed\n");
  } 
}

double problem_1(double x) {
  double f  = -2.2 * pow(x, 4) + 3.5 * pow(x, 3) + 4.1 * pow(x, 2) + 3.3 * x - 2.7;
  double fp = -8.8 * pow(x, 3) + 10.5 * pow(x, 2) + 8.2 * x + 3.3;
  return x - f / fp;
}

double problem_2(double x) {
  double f  = -3 * cos(2 * x + 2) + exp(x + 1) - 2 * x - 30;
  double fp =  6 * sin(2 * x + 2) + exp(x + 1) - 2;
  return x - f / fp;
}

int main(void) {
  printf("(1)\n");
  newton(problem_1, 0.5);

  printf("(2)\n");
  double const PI = acos(-1);
  newton(problem_2, PI / 2);
  return 0;
}
