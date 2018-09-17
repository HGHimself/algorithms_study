#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double mod_basic(double a, double b);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying mod here.\n\n");


  clock_t start, end;
  double cpu_time_used;
  double res;

  double a = 1764218677667;
  double b = 208095570762977;

  //double a = 691;
  //double b = 10;

  printf("\n%f mod %f = %f\n", a, b, mod_basic(b, a));
  /*
  start = clock();
  res = gcd(a, b);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("gcd(%f, %f) = %f, %f seconds\n\n", a, b, res, cpu_time_used);
  */

}

/* Compute x mod y naively. */
double mod_basic(double x, double y) {
    double result = x;
    while (result >= y)  {
      printf("result is %f, y is %f", result, y);
      result -= y;
    }
    return result;
}
