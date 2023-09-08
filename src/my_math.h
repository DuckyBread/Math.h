#ifndef _MY_MATH_H_
#define _MY_MATH_H_

#include <float.h>
#include <limits.h>
#include <stdint.h>

#define MY_EPSILON (1e-06)
#define MY_VERY_SMALL_EPSILON (1e-11)
#define MY_VERY_VERY_SMALL_EPSILON (1e-26)
#define MY_PI (3.14159265358979323846264338327950288)
#define MY_E (2.71828182845904523536028747135266250)
#define MY_INFINITY (1.0 / 0.0)

#define my_NAN __builtin_nanf("0x7fc00000")
#define my_isnan(x) __builtin_isnan(x)
#define my_isfinite(x) __builtin_isfinite(x)
#define my_ifinf(x) __builtin_isinf(x)

long int my_abs(int x);  // вычисляет модуль целого числа
long double my_fabs(double x);  // вычисляет модуль с плавающей точкой

long double my_signl(double x);  // возвращает знак
int my_isInt(long double x);  //  возвращает является ли число целым

long double my_ceil(double x);   // округление вверх
long double my_floor(double x);  // округление вниз

double my_max(double x, double y);  // возвращает максимум

long double my_exp(double x);  // возвращает e, возведенное в степень x
long double my_pow(double base, double exp);  // возводит число в степень
long double my_powi(double base,
                    unsigned int exp);  // возводит число в целую степень
long double my_sqrt(double x);  // вычисляет квадратный корень

long double my_factorial(unsigned int x);  // факториал

long double my_fmod(double x, double y);  // остаток от деления double
long double my_fdiv(double x, double y);

long double my_log(double x);  // вычисляет натуральный логарифм

long double my_acos(double x);  // вычисляет арккосинус
long double my_asin(double x);  // вычисляет арксинус
long double my_atan(double x);  // вычисляет арктангенс

long double my_sin(double x);  // вычисляет синус
long double my_cos(double x);  // вычисляет косинус
long double my_tan(double x);  // вычисляет тангенс

#endif  // MY_MATH_H_
