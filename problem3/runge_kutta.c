#include "util.h"
#include "runge_kutta.h"

void step_runge_kutta(double h, State src, State dst) {
  State k1; calc(src, k1);

  State temp;
  for (int i = 0; i < 4; ++i) {
    temp[i] = src[i] + h / 2 * k1[i];
  }
  State k2; calc(temp, k2);

  for (int i = 0; i < 4; ++i) {
    temp[i] = src[i] + h / 2 * k2[i];
  }
  State k3; calc(temp, k3);

  for (int i = 0; i < 4; ++i) {
    temp[i] = src[i] + h * k3[i];
  }
  State k4; calc(temp, k4);

  for (int i = 0; i < 4; ++i) {
    dst[i] = src[i] + h / 6 * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
  }
}
