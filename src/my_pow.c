#include "my_math.h"

long double my_pow(double base, double exp) {
  long double lld_base = base;
  long double ret_value = 0;
  if (my_isInt(exp) && exp > 0) {
    ret_value = my_powi(base, (unsigned int)exp);
  } else {
    if (my_fabs(exp) < MY_EPSILON) {
      ret_value = 1;
    } else if (my_fabs(base) < MY_EPSILON) {
      ret_value = 0;
    } else if (lld_base > 0) {
      ret_value = my_exp(exp * my_log(lld_base));
    } else if (!my_isInt(exp)) {
      ret_value = my_NAN;
    }
  }

  return ret_value;
}
