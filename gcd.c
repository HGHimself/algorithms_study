#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <float.h>

double gcd(double a, double b);
double mod(double x, double y);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying gcd here.\n\n");


  clock_t start, end;
  double cpu_time_used;
  double res;

  double a = 1764218677667;
  double b = 208095570762977;
  //double a = 691;
  //double b = 10;
  //printf("\n%f - %f = %f\n", b, a, b - a);
  //double a = 691;
  //double b = 10;

  //printf("%f mod %f = %f", a, b, gcd(a, b));

  start = clock();
  res = gcd(a, b);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("gcd(%f, %f) = %f, %f seconds\n\n", a, b, res, cpu_time_used);


}

double gcd(double a, double b) {
  if (0 == a || a == b) return b;
  double q, r;
  if(a > b)  {
    r = mod(a, b);
    q = (a - r) / b;
  }
  else  {
    r = mod(b, a);
    q = (b - r) / a;
  }
  printf("%f = (%f)(%f) + %f\n", a, b, q, r);


  return gcd(r, a);
}

double mod(double x, double y) {
  int64_t modulus = x, divisor = y;

  while (divisor <= modulus && divisor <= DBL_MAX/2)  {
    divisor <<= 1;
  }

  while (modulus >= y) {
    while (divisor > modulus)  {
      divisor >>= 1;
    }
    modulus -= divisor;
  }

  return modulus;
}
