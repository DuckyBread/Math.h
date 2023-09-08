#include "my_math.h"

long double my_asin(double x) { return my_atan(x / my_sqrt(1 - x * x)); }
