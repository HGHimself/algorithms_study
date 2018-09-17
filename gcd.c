#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double gcd(double a, double b);
double mod(double a, double b);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying gcd here.\n\n");


  clock_t start, end;
  double cpu_time_used;
  double res;

  double a = 1764218677667;
  double b = 208095570762977;

  //double a = 691;
  //double b = 10;

  printf("%f mod %f = %f", a, b, mod(a, b));
  /*
  start = clock();
  res = gcd(a, b);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("gcd(%f, %f) = %f, %f seconds\n\n", a, b, res, cpu_time_used);
  */

}

double gcd(double a, double b) {
    if (0 == a) return b;
    return gcd(b / a, a);
}

double mod(double a, double b)  {
  //a / b = q/b + r/b
  return (a / b);
}
