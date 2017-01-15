#include <math.h>
#include "mathutil.h"

int powi(int a, int n) {
  return n == 0 ? 1 : n % 2 == 0 ? powi(a * a, n / 2) : a * powi(a, n - 1);
}
