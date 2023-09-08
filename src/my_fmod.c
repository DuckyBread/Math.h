#include "my_math.h"

long double my_fmod(double x, double y) {
  long double result = 0;
  long long int mod = x / (long double)y;
  result = x - mod * (long double)y;
  if (y == MY_INFINITY || y == -MY_INFINITY) {
    result = x;
  }
  return (x == MY_INFINITY || x == -MY_INFINITY || y == 0) ? my_NAN : result;
}
