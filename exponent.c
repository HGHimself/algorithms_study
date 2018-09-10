#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float power_recursive(float base, int power);
float power_dynamic(float base, int power);
float iPow(float a, int e);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying exponents here.\n\n");

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


  start = clock();
  res = power_dynamic(base, power);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("power_dynamic(%d, %d) = %f, %f seconds\n\n", base, power, res, cpu_time_used);


  start = clock();
  res = iPow(base, power);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("iPow(%d, %d) = %f, %f seconds\n\n", base, power, res, cpu_time_used);

}

float power_recursive(float base, int power)  {
  printf("we got a base of %f and a power of %d\n", base, power);
  if(0 == base) return 0;
  if(0 == power) return 1;
  if(1 == power) return base;
  if(1 > power) return 1 / power_recursive(base, -power);
  return base * power_recursive(base, power - 1);
}

float power_dynamic(float base, int power)  {
  printf("we got a base of %f and a power of %d\n", base, power);
  float n;
  if(0 == power) return 1;
  n = power_dynamic(base, power/2);
  if(0 == power%2) return n*n;
  if(power > 0) return base*n*n;
  return (n*n)/base;
}

//stole this from internet
//clearly some magic going on here
//jk its the same as the one above just more bitwise operations
//O(logn)
float iPow(float a, int e) {
    float r = 1;
    if (e == 0) return r;
    while (e != 0) {
        //here this bitwise & becomes 1 if e is odd
        if ((e & 1) == 1) r *= a;
        //right shift divides by two
        e >>= 1;
        a *= a;
        printf("a is %f, r is %f, e is %d\n", a, r, e);
    }
    return r;
}
