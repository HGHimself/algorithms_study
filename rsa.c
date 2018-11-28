#include <stdio.h>
#include <stdint.h>
#include <float.h>
#include <stdlib.h>

void key_generation(uint64_t p, uint64_t q, uint64_t* den);
uint64_t encrypt(uint64_t m, uint64_t e, uint64_t n);
uint64_t decrypt(uint64_t c, uint64_t d, uint64_t n);
uint64_t modular_pow(uint64_t base, uint64_t exponent, uint64_t modulus);
uint64_t* extended_euclid(uint64_t a, uint64_t b, uint64_t* dxy);
uint64_t mod(uint64_t a, uint64_t b);
uint64_t gcd(uint64_t a, uint64_t b);
uint64_t lcm(uint64_t a, uint64_t b);
uint64_t lambda(uint64_t p, uint64_t q);
uint64_t euler_phi(uint64_t n);
uint64_t modular_linear_equation(uint64_t a, uint64_t b, uint64_t n, uint64_t x_n);

int main(void)  {
  printf("\nHello world!\n");
  // Choose two distinct prime numbers p and q.
  uint64_t p = 53;
  uint64_t q = 61;
  uint64_t den[3];
  key_generation(p, q, den);

  uint64_t m = 65;
  printf("message is %llu\n", m);

  uint64_t c = encrypt(m, den[1], den[2]);
  printf("encrypted message is %llu\n", c);

  uint64_t t = decrypt(c, den[0], den[2]);
  printf("decrypted message is %llu\n\n", t);
}

void key_generation(uint64_t p, uint64_t q, uint64_t *den)  {
  // Compute n = pq.
  uint64_t n = p * q;

  // Compute λ(n) = lcm(λ(p), λ(q)) = lcm(p − 1, q − 1),
  // where λ is Carmichael's totient function.
  uint64_t labmda_n = lambda(p, q);

  // Choose an integer e such that 1 < e < λ(n) and gcd(e, λ(n)) = 1.
  uint64_t e = 17;
  while(gcd(e, labmda_n) != 1 && e < labmda_n)  {
    e++;
  }

  // Determine d as d ≡ e−1 (mod λ(n));
  // i.e., d is the modular multiplicative inverse of e modulo λ(n).
  uint64_t d = modular_linear_equation(e, 1, labmda_n, 1);

  den[0] = d;
  den[1] = e;
  den[2] = n;
}

uint64_t encrypt(uint64_t m, uint64_t e, uint64_t n)  {
  //c(m) = m^e mod n
  return modular_pow(m, e, n);
}

uint64_t decrypt(uint64_t c, uint64_t d, uint64_t n)  {
  return modular_pow(c, d, n);
}

uint64_t modular_pow(uint64_t base, uint64_t exponent, uint64_t modulus)  {
  uint64_t res = 1;      // Initialize result
  base = base % modulus;  // Update x if it is more than or
                    // equal to p
  while (exponent > 0)  {
      // If y is odd, multiply x with result
      if (exponent & 1) res = (res*base) % modulus;

      // y must be even now
      exponent = exponent >> 1;
      base = (base*base) % modulus;
  }
  return res;
}

uint64_t* extended_euclid(uint64_t a, uint64_t b, uint64_t* dxy)  {
  if(b == 0)  {
    dxy[0] = a;
    dxy[1] = 1;
    dxy[2] = 0;
    return dxy;
  }
  else  {
    uint64_t* dxy_prime = extended_euclid(b, mod(a,b), dxy);
    uint64_t number = ((a/b) * dxy_prime[2]);
    uint64_t y_prime = dxy_prime[1] - number;
    //printf("a:%llu, b:%llu, (a/b):%llu, d:%llu, x:%llu, y:%llu\n", a, b, (a/b), dxy_prime[0], dxy_prime[1], dxy_prime[2]);
    dxy[0] = dxy_prime[0];
    dxy[1] = dxy_prime[2];
    dxy[2] = y_prime;
    return dxy;
  }
}


uint64_t mod(uint64_t a, uint64_t b) {
  uint64_t modulus = a, divisor = b;
  while (divisor <= modulus && divisor <= DBL_MAX/2)  {
    divisor <<= 1;
  }
  while (modulus >= b) {
    while (divisor > modulus)  {
      divisor >>= 1;
    }
    modulus -= divisor;
  }
  return modulus;
}

uint64_t gcd(uint64_t a, uint64_t b) {
  if (0 == a || a == b) return b;
  uint64_t q, r;
  if(a > b)  {
    r = mod(a, b);
    q = (a - r) / b;
  }
  else  {
    r = mod(b, a);
    q = (b - r) / a;
  }
  return gcd(r, a);
}

uint64_t lcm(uint64_t a, uint64_t b)  {
  return (a*b)/gcd(a, b);
}

uint64_t lambda(uint64_t p, uint64_t q)  {
  return lcm(p - 1, q - 1);
}

uint64_t euler_phi(uint64_t n)  {
	uint64_t count = 0;
	for(uint64_t i = 0; i < n + 1; i++) {
		if(1 == gcd(n, i)) count++;
	}
	return count;
}

// a x === b (mod n)
uint64_t modular_linear_equation(uint64_t a, uint64_t b, uint64_t n, uint64_t x_n)  {
  uint64_t table[3];
  uint64_t* dxy = extended_euclid(a, n, table);

  uint64_t d = dxy[0];
  uint64_t x = dxy[1];

  uint64_t x_naught = x * (b / d);
  return x_naught + x_n * (n / d);
}
