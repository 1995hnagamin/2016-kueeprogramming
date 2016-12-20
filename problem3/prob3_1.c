#include <stdio.h>
#include <math.h>
#include "util.h"
#include "heun.h"

int main(void) {
  calc_and_print(step_heun, 64, 5);
  return 0;
}
