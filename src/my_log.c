#include "my_math.h"

long double my_log(double x) {
  double result = my_NAN;
  int ex_pow = 0;

  if (x == 1) {
    result = 0;
  } else if (x == 0) {
    result = -MY_INFINITY;
  } else if (my_fabs(x) < MY_EPSILON) {
    result = my_NAN;
  } else if (!my_isfinite(x) && !my_isnan(x) && x > MY_EPSILON) {
    result = MY_INFINITY;
  } else if (x > MY_EPSILON) {
    result = 0;
    double compare = 0;
    for (; x >= MY_E; x /= MY_E, ex_pow++) continue;

    for (int i = 0; i < 200; i++) {
      compare = result;
      result = compare + 2 * (x - my_exp(compare)) / (x + my_exp(compare));
    }
  }

  return result + ex_pow;
}
