#include "my_math.h"
#define _MY_INT_MSB (1l << (__INT_WIDTH__ - 1))

long double my_powi(double base, unsigned int exp) {
  long double result = 1;

  unsigned int mask = _MY_INT_MSB;

  for (; mask; mask = mask >> 1) {
    result *= result;
    if (exp & mask) {
      result *= base;
    }
  }
  return result;
}
