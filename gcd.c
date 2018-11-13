#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <float.h>

double gcd(double a, double b);
double mod(double x, double y);
int euclid(int a, int b);
int* extended_euclid(int a, int b, int* dxy);
int modular_linear_equation(int a, int b, int n, int x_n);
int euler_phi(int n);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying gcd here.\n\n");


  clock_t start, end;
  double cpu_time_used;
  int res;

  int a = 255;
  int n = 16;
  int b = 10;
  int x_n = 1;
  int x = modular_linear_equation(a, b, n, x_n);
  printf("\n %d(%d) ~= %d (mod %d)\n", a, x, b, n);

  /*

  start = clock();
  res = euclid(a, b);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("euclid(%d, %d) = %d, %f seconds\n\n", a, b, res, cpu_time_used);

  start = clock();
  double resd = gcd((double)a, (double)b);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("gcd(%d, %d) = %f, %f seconds\n\n", a, b, resd, cpu_time_used);

  int* table = malloc(sizeof(int) * 3);
  start = clock();
  int* dxy = extended_euclid(a, b, table);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("gcd(%d, %d) = (%d, %d, %d), %f seconds\n\n", a, b, dxy[0], dxy[1], dxy[2], cpu_time_used);
  */

}

//O(lg(b))
//doesnt matter if a>b or b<a because mod will flip accordingly
int euclid(int a, int b)  {
  if(b == 0) return a;
  else return euclid(b, a % b);
}

int* extended_euclid(int a, int b, int* dxy)  {
  if(b == 0)  {
    printf("found!\n");
    dxy[0] = a;
    dxy[1] = 1;
    dxy[2] = 0;
    return dxy;
  }
  else  {
    printf("deeper\n");
    int* dxy_prime = extended_euclid(b, a % b, dxy);
    int number = ((a/b) * dxy_prime[2]);
    int y_prime = dxy_prime[1] - number;
    printf("a:%d, b:%d, (a/b):%d, d:%d, x:%d, y:%d\n", a, b, (a/b), dxy_prime[0], dxy_prime[1], dxy_prime[2]);
    dxy[0] = dxy_prime[0];
    dxy[1] = dxy_prime[2];
    dxy[2] = y_prime;
    return dxy;
  }
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

int modular_linear_equation(int a, int b, int n, int x_n)  {

  int* table = malloc(sizeof(int) * 3);
  int* dxy = extended_euclid(a, n, table);

  int d = dxy[0];
  int x = dxy[1];

  int x_naught = x * (b / d);

  return x_naught + x_n * (n / d);
}


int euler_phi(int n)  {
	int count = 0;
	for(int i = 0; i < n + 1; i++) {
		if(1 == euclid(n, i)) count++;
	}
	return count;
}
