#include <stdio.h>

#include "my_math.h"

long double my_ceil(double x) {
  long double floor_x = (long long int)x;
  if (!my_isfinite(x) && !my_isnan(x)) {
    floor_x = MY_INFINITY;
  } else if (my_isnan(x)) {
    floor_x = my_NAN;
  } else if (my_fabs(x - floor_x) > 0. && my_fabs(x) > 0.) {
    if (x >= 0.) {
      floor_x += 1;
    }
  }
  return floor_x;
}
