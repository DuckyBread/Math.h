#include "my_math.h"

long double my_exp(double x) {
  long double series_member = 1;
  long double prev_appr = 0;
  long double series = 1.0;
  double sign = x < 0 ? -1 : 1;
  x = my_fabs(x);
  unsigned long long int i = 1;
  while (my_fabs(series - prev_appr) > 1e-16 && i < UINT64_MAX &&
         series < DBL_MAX) {
    series_member *= (x / (long double)i);
    prev_appr = series;
    series += series_member;
    if (series > DBL_MAX) {
      series = MY_INFINITY;
    }
    i++;
  }
  if (sign < 0) series = 1 / series;

  return series;
}
