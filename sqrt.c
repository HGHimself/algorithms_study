#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying the roots here.\n\n");

  int base = 5;
  int power = 20;

  clock_t start, end;
  double cpu_time_used;
  float res;

  start = clock();
  res = power_recursive(base, power);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("power_recursive(%d, %d) = %f, %f seconds\n\n", base, power, res, cpu_time_used);


}

/*
according to newton’s method
x(K+1) = x(K) – f(x) / f’(x)
here    f(x)  = x^(N) – A
so    f’(x) = N*x^(N - 1)
and     x(K) denoted the value of x at Kth iteration
putting the values and simplifying we get,
x(K + 1) = (1 / N) * ((N - 1) * x(K) + A / x(K) ^ (N - 1))
*/
