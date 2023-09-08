#include "my_math.h"

long double my_sqrt(double x) {
  long double mid;
  if (x < 0) {
    mid = my_NAN;
  } else {
    long double left = 0;
    long double right = my_max(1, x);

    mid = (left + right) / 2;
    while ((mid - left) > MY_EPSILON) {
      if (mid * mid > x) {
        right = mid;
      } else {
        left = mid;
      }
      mid = (left + right) / 2;
    }
  }
  return mid;
}
