#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float mysqrt(int x);
float n_root(int root, int n);
float abs_float(float n);
int abs_int(int n);
float power(float base, int exp);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying the roots here.\n\n");

  int root = 8;
  int n = 3;

  clock_t start, end;
  double cpu_time_used;
  float res;

  start = clock();
  res = n_root(root, n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("n_root(%d, %d) = %f, %f seconds\n\n", root, n, res, cpu_time_used);


}

/*
newton's method

x_n = x_n-1 - 1/f`(x_n-1) * f(x_n-1)

here f(x) = x^2
so   f`(x) = 2x


*/
float mysqrt(int x)  {
  float z = x;
	float z_last = 1;
	for (int i = 0; i < 10; i++){
		z -= (z*z - x) / (2*z);
		float dif = abs_float(z_last - z);
    printf("%f is z, %f is the dif\n", z, dif);
		if(dif < 0.00000001) return z;
		z_last = z;
	}
	return z;
}

float n_root(int root, int n)  {
  float z = root;
	float z_last = 1;
	for (int i = 0; i < 10; i++){
    float exp = power(z, n);
		z -= (exp - root) / (n*z);
		float dif = abs_float(z_last - z);
    printf("%f is z, %f is the dif\n", z, dif);
		if(dif < 0.00000001) return z;
		z_last = z;
	}
	return z;
}

float abs_float(float n)  {
  if(n < 0) return -n;
  else return n;
}

int abs_int(int n)  {
  if(n < 0) return -n;
  else return n;
}

float power(float base, int exp)  {
  float n;
  if(0 == exp) return 1;
  n = power(base, exp/2);
  if(0 == exp%2) return n*n;
  if(exp > 0) return base*n*n;
  return (n*n)/base;
}
