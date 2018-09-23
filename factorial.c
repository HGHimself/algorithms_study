#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int factorial_recursive(int n);
double factorial_recursive_double(double n);
double factorial_dynamic_primer(double n);
double factorial_dynamic(double n, double *table);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying factorials here.\n\n");

  int n = 13;

  clock_t start, end;
  double cpu_time_used;
  int res;

  start = clock();
  res = factorial_recursive(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("factorial_recursive(%d) = %d, %f seconds\n\n", n, res, cpu_time_used);


  start = clock();
  double resD = factorial_recursive_double((double)n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("factorial_recursive(%d) = %f, %f seconds\n\n", n, resD, cpu_time_used);


  start = clock();
  resD = factorial_dynamic_primer((double)n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("factorial_dynamic(%d) = %f, %f seconds\n\n", n, resD, cpu_time_used);


}

int factorial_recursive(int n)  {
  //printf("n here is %f\n", n);
  if(1 == n) return 1;
  if(-1 == n) return -1;
  if(0 == n) return 0;
  if(0 > n) return n * factorial_recursive(n + 1);
  return n * factorial_recursive(n - 1);
}

double factorial_recursive_double(double n)  {
  //printf("n here is %f\n", n);
  if(1 == n) return 1;
  if(-1 == n) return -1;
  if(0 == n) return 0;
  if(0 > n) return n * factorial_recursive(n + 1);
  return n * factorial_recursive(n - 1);
}

double factorial_dynamic_primer(double n)  {
  double* table = calloc(n, sizeof(double));
  double r = factorial_dynamic(n, table);
  free(table);
  return r;
}

double factorial_dynamic(double n, double *table)  {
  //printf("n here is %f\n", n);
  if(0 == n) return 1;
  if(0 != table[(size_t)n]) return table[(size_t)n];
  int x = factorial_dynamic(n - 1, table) * n;
  table[(size_t)n] = x;
  return x;
}
