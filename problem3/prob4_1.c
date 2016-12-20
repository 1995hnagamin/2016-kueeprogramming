#include <stdio.h>
#include <math.h>
#include "util.h"
#include "runge_kutta.h"

int main(void) {
  calc_and_print(step_runge_kutta, 64, 5);
  return 0;
}
