#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <float.h>

int main(void)  {
  int a = 100242;
  int b = 200123;
  printf("a:%d, b:%d\na %% b = %d\nb %% a = %d\n\n", a, b, a % b, b % a);
}
