#include "util.h"
#include "euler.h"

void step_euler(double h, State src, State dst) {
  State temp;
  calc(src, temp);
  for (int i = 0; i < 4; ++i) {
    dst[i] = src[i] + h * temp[i];
  }
}
