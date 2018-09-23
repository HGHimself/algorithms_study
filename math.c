#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void binomial_theorem(int x, char a, int y, char b, int n);
int permutation(int n, int k);
int choose(int n, int k);
int factorial(int n);
float power(float base, int power);
int congruence_mod(int a, int b, int n);

int main(void)  {
  printf("\n\nHello World\n\n");

  clock_t start, end;
  double cpu_time_used;

  start = clock();
  binomial_theorem(4, 'x', 1, '1', 4);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("\n\n%f seconds\n\n", cpu_time_used);

}

void binomial_theorem(int x, char a, int y, char b, int n)  {
  int j = 0;
  int c = 0;

  for(j = 0; j <= n; j++)  {
    //printf("j:%d n:%d\n", j, n);
    c=0;
    c = choose(n, j);
    if('1' == a) printf("%d(%c^%d) +", c, b, j);
    else if('1' == b) printf("%d(%c^%d) +", c, a, n-j);
    else printf("%d(%c^%d)(%c^%d) +", c, a, n-j, b, j);
  }
}

int permutation(int n, int k)  {
  if(k > n) return 0;

  int total = 1;
  int i = 0;

  for(i = k - 1; i >= 0; i--)  {
    total *= n - i;
  }

  return total;
}

int choose(int n, int k)  {
  if(k > n) return 0;
  if(0 == n || n == k) return 1;
  //use symetry to make comp easier
  if(n - k < k) k = n - k;

  int numerator = permutation(n, k);
  int denominator = factorial(k);

  return numerator / denominator;
}

int factorial(int n)  {
  if(1 == n) return 1;
  if(-1 == n) return -1;
  if(0 == n) return 1;
  if(0 > n) return n * factorial(n + 1);
  return n * factorial(n - 1);
}

float power(float base, int power)  {
  float n;
  if(0 == power) return 1;
  n = power(base, power/2);
  if(0 == power%2) return n*n;
  if(power > 0) return base*n*n;
  return (n*n)/base;
}

// a === b (mod n)
int congruence_mod(int a, int b, int n)  {
  int dif = 0;
  if(a > b) dif = a - b;
  else if(a < b) dif = b - a;
  else return 1;
  //n|b-a
  if(n % dif == 0) return 1;
  else return 0;
}
