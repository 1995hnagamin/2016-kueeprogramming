#include <stdio.h>
#include <math.h>
#include "util.h"
#include "euler.h"

int main(void) {
  calc_and_print(step_euler, 64, 5);
  return 0;
}
