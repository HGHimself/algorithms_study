#include <stdlib.h>
#include <stdio.h>

int fibonacci_recursive(int n, int count);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying the fibonacci numbers here.\n\n");

  int n = 9;
  printf("Fibonacci(%d) = %d\n", n, fibonacci_recursive(n, 0));

}

//Time complexity 
int fibonacci_recursive(int n, int count)  {
  count++;
  printf("here n is %d, count is %d\n", n, count);
  if(n <= 1) return n;
  return fibonacci_recursive(n - 1, count) + fibonacci_recursive(n - 2, count);
}
