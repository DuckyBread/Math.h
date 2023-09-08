#include <stdio.h>

#include "my_math.h"

long double my_sin(double x) {
  long double sum_sin = 0;

  if (!my_isfinite(x) && !my_isnan(x)) {
    sum_sin = my_NAN;
  } else if (my_isnan(x)) {
    sum_sin = my_NAN;
  } else {
    for (; x < -2 * MY_PI || 2 * MY_PI < x;) {
      if (x > 2 * MY_PI) {
        x -= 2 * MY_PI;
      } else {
        x += 2 * MY_PI;
      }
    }
    for (register int i = 0; i < 150; i++) {
      sum_sin +=
          my_powi(-1, i) * my_powi(x, 2 * i + 1) / my_factorial(2 * i + 1);
    }
  }
  return sum_sin;
}
