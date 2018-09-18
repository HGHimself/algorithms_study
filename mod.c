#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <float.h>

double mod_basic(double a, double b);
double mod_bld(double x, double y);
double divide(double x, double y);

int main(void)  {
  printf("\n\nHello World!!\n\nWe are studying mod here.\n\n");


  clock_t start, end;
  double cpu_time_used;
  double res;

  double a = 208095570762977;
  double b = 1764218677667;

  //double a = 691;
  //double b = 10;
  /*
  start = clock();
  res = mod_basic(a, b);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("mod_basic(%f, %f) = %f, %f seconds\n\n", a, b, res, cpu_time_used);

  start = clock();
  res = mod_bld(a, b);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("mod_bld(%f, %f) = %f, %f seconds\n\n", a, b, res, cpu_time_used);
  */
  float result = mod_bld(27, 5);


}

/*
Compute x mod y naively.
This is bad, runs in O(x/y) or O(n)
*/
double mod_basic(double x, double y) {
  double result = x;
  while (result >= y)  {
    //printf("result is %f, y is %f\n", result, y);
    result -= y;
  }
  return result;
}

/*
Compute x mod y using binary long division.
Stupid doubles dont allow for binary operations
*/
double mod_bld(double x, double y)
{
  int64_t modulus = x, divisor = y;

  while (divisor <= modulus && divisor <= 2147483647/2)  {
    printf("divisor is %lld\n", divisor);
    divisor <<= 1;
  }


  while (modulus >= y) {
    printf("modulus is %lld\n", modulus);
    while (divisor > modulus)  {
      printf("divisor is %lld\n", divisor);
      divisor >>= 1;
    }
    modulus -= divisor;
  }

  return modulus;
}

void unsigned_divide(unsigned int dividend,
		     unsigned int divisor,
		     unsigned int &quotient,
		     unsigned int &remainder )
{
  unsigned int t, num_bits;
  unsigned int q, bit, d;
  int i;

  remainder = 0;
  quotient = 0;

  if (divisor == 0)
    return;

  if (divisor > dividend) {
    remainder = dividend;
    return;
  }

  if (divisor == dividend) {
    quotient = 1;
    return;
  }

  num_bits = 32;

  while (remainder < divisor) {
    bit = (dividend & 0x80000000) >> 31;
    remainder = (remainder << 1) | bit;
    d = dividend;
    dividend = dividend << 1;
    num_bits--;
  }


  /* The loop, above, always goes one iteration too far.
     To avoid inserting an "if" statement inside the loop
     the last iteration is simply reversed. */

  dividend = d;
  remainder = remainder >> 1;
  num_bits++;

  for (i = 0; i < num_bits; i++) {
    bit = (dividend & 0x80000000) >> 31;
    remainder = (remainder << 1) | bit;
    t = remainder - divisor;
    q = !((t & 0x80000000) >> 31);
    dividend = dividend << 1;
    quotient = (quotient << 1) | q;
    if (q) {
       remainder = t;
     }
  }
}  /* unsigned_divide */


void signed_divide(int dividend,
		   int divisor,
		   int &quotient,
		   int &remainder )
{
  unsigned int dend, dor;
  unsigned int q, r;

  dend = absolute_value(dividend);
  dor  = absolute_value(divisor);
  unsigned_divide( dend, dor, q, r );

  /* the sign of the remainder is the same as the sign of the dividend
     and the quotient is negated if the signs of the operands are
     opposite */
  quotient = q;
  if (dividend < 0) {
    remainder = -r;
    if (divisor > 0)
      quotient = -q;
  }
  else { /* positive dividend */
    remainder = r;
    if (divisor < 0)
      quotient = -q;
  }

} /* signed_divide */

double absolute_value(double x)  {
  if(x >= 0) return x;
  else return -x;
}
