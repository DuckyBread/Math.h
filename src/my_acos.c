#include "my_math.h"

long double my_acos(double x) {
  long double sum;
  if (x != x) {
    sum = x;
  } else {
    sum = (MY_PI / 2) - my_asin(x);
  }
  return sum;
}
