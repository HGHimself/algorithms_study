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


  start = clock();
  res = power_dynamic(base, power);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("power_dynamic(%d, %d) = %f, %f seconds\n\n", base, power, res, cpu_time_used);

}

//stole this from the internet
int root(int a, int n) {
    int v = 1, bit, tp, t;
    if (n == 0) return 0; //error: zeroth root is indeterminate!
    if (n == 1) return a;
    tp = iPow(v,n);
    while (tp < a) {    // first power of two such that v**n >= a
        v <<= 1;
        tp = iPow(v,n);
    }
    if (tp == a) return v;  // answer is a power of two
    v >>= 1;
    bit = v >> 1;
    tp = iPow(v, n);    // v is highest power of two such that v**n < a
    while (a > tp) {
        v += bit;       // add bit to value
        t = iPow(v, n);
        if (t > a) v -= bit;    // did we add too much?
        else tp = t;
        if ( (bit >>= 1) == 0) break;
    }
    return v;   // closest integer such that v**n <= a
}
