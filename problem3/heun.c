#include "util.h"
#include "heun.h"

void step_heun(double h, State src, State dst) {
  double k1[4]; calc(src, k1);

  double temp[4];
  for (int i = 0; i < 4; ++i) {
    temp[i] = src[i] + h * k1[i];
  }
  double k2[4]; calc(temp, k2);

  for (int i = 0; i < 4; ++i) {
    dst[i] = src[i] + (k1[i] + k2[i]) * h / 2;
  }
}
