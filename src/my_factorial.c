#include "my_math.h"

long double my_factorial(unsigned int x) {
  return (x == 0) ? 1.0 : x * my_factorial(x - 1);
}
