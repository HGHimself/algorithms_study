# Algorithms

## Divisibility
- d|a reads "d divides a"
- this means that a = kd for some integer k
- Every integer divides 0
- if a > 0 and d|a then abs(d) <= abs(a)
- if d|a, then we say a is a *multiple* of d
- if d|a, then we say d is a *divisor* of a

### Primes
- integer a > 1 whose only divisors are 1 and a is called *prime*
- a number that is not prime is called *composite*
- 1 is a *unit*
- 0 and all negative numbers are neither prime nor composite

### Division Theorem
- for any integer a and n > 0, there exists unique integers q and r such that
  * ```a = qn + r where 0 <= r < n```
- the value q = floor(a/n) is called the *quotient*
- the value r = a mod n is called the *remainder*
- n|a if and only if a mod n = 0
- we can partition the integers into equivalence classes mod n
  * ```[a]_n = {a + kn: k is element of Z}```
  * ```a is element of [b]_n == a congruent b (mod n)```
  * ```Z_n = {[a]_n : 0 <= a <= n-1}```

### Greatest Common Divisor
- if d|a and d|b then d is a *common divisor* of a and b
- properties of common divisors
  * d|a and d|b implies d|(a+b) and d|(a-b)
  * d|a and d|b implies d|(ax+by) for any integer x and y
  * a|b and b|a implies a = +-b
- properties of greatest common divisor
  * ```gcd(a, b) = gcd(b, a)```
  * ```gcd(a, b) = gcd(-a, b)```
  * ```gcd(a, b) = gcd(|b|, |a|)```
  * ```gcd(a, 0) = |a|```
  * ```gcd(a, ka) = |a|```
- if a and b are any non-zero integers, then gcd(a,b) is the smallest possible element of the set {ax + by: x,y are elements of Z} of linear combinations of a and b

### Relatively Prime
- two integers a, b are relatively prime if gcd(a,b) = 1
- if two integers are relatively prime to a prime p, then their product is also relatively prime to p
  * this is because a and b have no relation(prime factor) of p, so their product won't magically add that factor in

### Unique Factorization
- for all primes p and all integers a and b, if p|ab, then p|a or p|b (or both)
  * opposite of above, meaning if there is a common prime factor p in a or b, then it will still be present in a(b)

## GCD

### Recursive Theorem
- gcd(a,b) = gcd(b, a mod b)
- my attempt at a proof:
- showing that above equation holds using *a|b and b|a implies a = +-b*
  * ```a mod b = r``` and ```a = qb + r``` (division theorem)
  * so ```a mod b = r = a - q(b)```
  * d|a and d|b implies d|(ax+by) for any integer x and y (properties of common divisors)
  * since ```gcd(a,b) = d => d|a and d|b```
  * then ```d|(ax+by) => a - q(b) = (1)a + (-q)b = a mod b```
  * since a mod b is a linear combination, its implied that d|(a mod b)
  * therefore since d|b and d|(a mod b) => *gcd(a,b)|gcd(b,a mod b)*
- for the other direction:
  * assume ```gcd(b, a mod b) = d```
  * therefore d|b and d|(a mod b)
  * since ```a = qb + (a mod b)```(division theorem)
  * a is a linear combination of b and (a mod b)
  * from the properties of common divisors, we can conclude that d|a
  * therefore since d|a and d|b => *gcd(b, a mod b)|gcd(b,a)*
- Since *gcd(a,b)|gcd(b,a mod b)* and *gcd(b, a mod b)|gcd(b,a)*, we can conclude that *gcd(a,b) = gcd(b, a mod b)*
