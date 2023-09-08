#include "my_math.h"

static long double my_atan_taylor(double x) {
  long double ret_value = 0;
  long double prev_val = -1;
  long long unsigned i = 1;
  int sign = 1;
  while (my_fabs(ret_value - prev_val) > 1e-16) {
    long double member =
        sign * my_powi(x, 2 * i - 1) / (long double)(2 * i - 1);
    prev_val = ret_value;
    ret_value += member;
    i++;
    sign *= -1;
  }
  return ret_value;
}

long double my_atan(double x) {
  long double ret_val;
  if (x < -1) {
    ret_val = -(MY_PI / 2 + my_atan_taylor(1.0 / x));
  } else if (x < 1 && x > -1) {
    ret_val = my_atan_taylor(x);
  } else if (x == 1) {
    ret_val = 0.785398163397448;
  } else if (x == -1) {
    ret_val = -0.785398163397448;
  } else {
    ret_val = MY_PI / 2 - my_atan_taylor(1.0 / x);
  }
  return ret_val;
}
