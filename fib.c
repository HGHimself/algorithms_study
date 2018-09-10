#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int fibonacci_recursive(int n, int count);
int fibonacci_dynamic(int n);
int fibonacci_optimized(int n);
int fibonacci_matrix(int n);
void power(int FIB[2][2], int n);
void multiply(int FIB[2][2], int MAT[2][2]);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying the fibonacci numbers here.\n\n");
  //Note that we are using ints here so 46 is the highest you can go
  //since fib(47) = 2971215073
  //ints can hold   2147483647 
  int n = 45;

  clock_t start, end;
  double cpu_time_used;
  int res;

  start = clock();
  res = fibonacci_recursive(n, 0);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Fibonacci_recursive(%d) = %d, %f seconds\n", n, res, cpu_time_used);

  start = clock();
  res = fibonacci_dynamic(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Fibonacci_dynamic(%d) = %d, %f seconds\n", n, res, cpu_time_used);

  start = clock();
  res = fibonacci_optimized(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Fibonacci_optimized(%d) = %d, %f seconds\n", n, res, cpu_time_used);

  start = clock();
  res = fibonacci_matrix(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Fibonacci_matrix(%d) = %d, %f seconds\n", n, res, cpu_time_used);

}

/*
This uses recursion to find the n-th fibonacci numbers
F_0 = 0;
F_1 = 1;
F_n = F_n-1 + F_n-2

it builds a function call tree top-down
then when each case is broken into a base case (0 or 1)
it solves in a bottom-up manner

                          fib(5)
                    /              \
              fib(4)                  fib(3)
            /       \                /       \
      fib(3)        fib(2)        fib(2)          fib(1)
    /      \       /      \        /     \
fib(2)    fib(1)  fib(1) fib(0) fib(1) fib(0)
/     \
fib(1) fib(0)

here when n = 9, the below printf runs 109 times
count, which keeps track of the stack call size is at most 9

Time: T(n) = T(n-1) + T(n-2) (exponential)
Space: O(n)
*/
int fibonacci_recursive(int n, int count)  {
  count++;
  //printf("here n is %d, count is %d\n", n, count);
  if(1 >= n) return n;
  return fibonacci_recursive(n - 1, count) + fibonacci_recursive(n - 2, count);
}

/*
This uses dynamic programming to save the CPU from doing repeated work
We store each F_n value for later usage

F_0 = 0
F_1 = 1
F_2 = F_1 + F_0 => F_3 = F_2 + F_1 => ... => F_n = F_n-1 + F_n-2

each prior F value is calculated and reused

Time: O(n)
Space: O(n)
*/
int fibonacci_dynamic(int n)  {
  int fib[n + 2];
  int i;
  int count = 0;

  fib[0] = 0;
  fib[1] = 1;

  for(i = 2; i <= n; i++)   {
    count++;
    fib[i] = fib[i-1] + fib[i-2];
    //printf("Here n is %d, count is %d\n", i, count);
  }

  return fib[n];
}

/*
Modified version from above
Only stores Fn-1 and Fn-2

Time: O(n)
Space: O(1)
*/
int fibonacci_optimized(int n)  {
  int f_l = 0, f_m = 1, f_n, i;

  if(0 == n) return f_l;

  for (i = 2; i <= n; i++)  {
    f_n = f_m + f_l;
    f_l = f_m;
    f_m = f_n;
  }
  return f_m;
}

/*
still need to learn how this works but essentially it runs in O(logn)
*/
int fibonacci_matrix(int n)  {
  if (0 == n) return 0;
  int FIB[2][2] = {{1,1},{1,0}};
  power(FIB, n-1);
  return FIB[0][0];
}

void power(int FIB[2][2], int n)  {
  if(0 == n || 1 == n) return;
  int MAT[2][2] = {{1,1},{1,0}};

  power(FIB, n/2);
  multiply(FIB, FIB);

  if (n%2 != 0) multiply(FIB, MAT);
}

void multiply(int FIB[2][2], int MAT[2][2])  {
  int m00 = FIB[0][0]*MAT[0][0] + FIB[0][1]*MAT[1][0];
  int m01 = FIB[0][0]*MAT[0][1] + FIB[0][1]*MAT[1][1];
  int m10 = FIB[1][0]*MAT[0][0] + FIB[1][1]*MAT[1][0];
  int m11 = FIB[1][0]*MAT[0][1] + FIB[1][1]*MAT[1][1];

  FIB[0][0] = m00;
  FIB[0][1] = m01;
  FIB[1][0] = m10;
  FIB[1][1] = m11;
}
