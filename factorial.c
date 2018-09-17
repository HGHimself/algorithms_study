#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double factorial_recursive(double n);
double factorial(double n);
double factorial_dynamic(double n, double *table);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying factorials here.\n\n");

  double n = 10;

  clock_t start, end;
  double cpu_time_used;
  double res;

  start = clock();
  res = factorial_recursive(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("factorial_recursive(%f) = %f, %f seconds\n\n", n, res, cpu_time_used);

  start = clock();
  res = factorial(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("factorial_dynamic(%f) = %f, %f seconds\n\n", n, res, cpu_time_used);


}

double factorial_recursive(double n)  {
  printf("n here is %f\n", n);
  if(1 == n) return 1;
  if(-1 == n) return -1;
  if(0 == n) return 0;
  if(0 > n) return n * factorial_recursive(n + 1);
  return n * factorial_recursive(n - 1);
}

double factorial(double n)  {
  double* table = calloc(n, sizeof(double));
  double r = factorial_dynamic(n, table);
  free(table);
  return r;
}

double factorial_dynamic(double n, double *table)  {
  printf("n here is %f\n", n);
  if(0 == n) return 1;
  if(0 != table[(size_t)n]) return table[(size_t)n];
  double x = factorial_dynamic(n - 1, table) * n;
  table[(size_t)n] = x;
  return x;
}
