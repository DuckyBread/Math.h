#include <stdio.h>

#include "my_math.h"

long double my_cos(double x) {
  long double sum_cos = 0;
  if (!my_isfinite(x) && !my_isnan(x)) {
    sum_cos = my_NAN;
  } else if (my_isnan(x)) {
    sum_cos = my_NAN;
  } else {
    for (; x < -2 * MY_PI || 2 * MY_PI < x;) {
      if (x > 2 * MY_PI) {
        x -= 2 * MY_PI;
      } else {
        x += 2 * MY_PI;
      }
    }
    for (register int i = 0; i < 150; i++) {
      sum_cos += my_powi(-1, i) * my_powi(x, 2 * i) / my_factorial(2 * i);
    }
  }
  return sum_cos;
}
