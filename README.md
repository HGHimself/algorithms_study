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
```
a = qn + r where 0 <= r < n
```
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
  *
