# Algorithms

## Divisibility
- d|a reads "d divides a"
- this means that a = kd for some integer k
- Every integer divides 0
- if a > 0 and d|a then abs(d) <= abs(a)
- if d|a, then we say a is a *multiple* of d
- if d|a, then we say d is a *divisor* of a

### Primes
- integer a > 1 whose only divisors are 1 and a is called **prime**
- a number that is not prime is called **composite**
- 1 is a **unit**
- 0 and all negative numbers are neither prime nor composite

### Division Theorem
- for any integer a and n > 0, there exists unique integers q and r such that
  * ```a = qn + r where 0 <= r < n```
- the value q = floor(a/n) is called the **quotient**
- the value r = a mod n is called the **remainder**
- n|a if and only if a mod n = 0
- we can partition the integers into equivalence classes mod n
  * ```[a]_n = {a + kn: k is element of Z}```
  * ```a is element of [b]_n == a congruent b (mod n)```
  * ```Z_n = {[a]_n : 0 <= a <= n-1}```

### Greatest Common Divisor
- if d|a and d|b then d is a **common divisor** of a and b
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
- showing that above equation holds using **a|b and b|a implies a = +-b**
  * ```a mod b = r``` and ```a = qb + r``` (division theorem)
  * so ```a mod b = r = a - q(b)```
  * **d|a and d|b implies d|(ax+by)** for any integer x and y (properties of common divisors)
  * since ```gcd(a,b) = d => d|a and d|b```
  * then ```d|(ax+by) => a - q(b) = (1)a + (-q)b = a mod b```
  * since a mod b is a linear combination of a and b, its implied that **d|(a mod b)**
  * therefore since d|b and d|(a mod b) => **gcd(a,b)|gcd(b,a mod b)**
- for the other direction:
  * assume ```gcd(b, a mod b) = d```
  * therefore d|b and d|(a mod b)
  * since ```a = qb + (a mod b)```(division theorem)
  * a is a linear combination of b and (a mod b)
  * from the properties of common divisors, we can conclude that d|a
  * therefore since d|a and d|b => **gcd(b, a mod b)|gcd(b,a)**
- Since **gcd(a,b)|gcd(b,a mod b)** and **gcd(b, a mod b)|gcd(b,a)**, we can conclude that **gcd(a,b) = gcd(b, a mod b)**

### Euclid's Algorithm
```
EUCLID(a,b)
  if b == 0
    return a
  else return EUCLID(b, a mod b)
```

- run time of above is proportional to the number of function calls it makes
- since consecutive Fibonacci numbers are always relatively prime, this puts a boof in the calculations
  * ```F_n+1 mod F_n = F_n-1```
  * so EUCLID(F_n+1, F_n) would make **n-1** function calls
- O(lg(b)) but I'm not entirely sure why yet.

### Extended Euclid
```
EXTENDED-EUCLID(a,b)
  if b == 0
    return(a,1,0)
  else (d', x', y') = EXTENDED-EUCLID(b, a mod b)
    (d,x,y) = (d', y', x' - (floor(a/b)) * y')
    return (d,x,y)
```
- ```d = gcd(a,b) = ax + by```

## Congruence
- an **equivalence relation** on **X** is a binary relation **~** such that
  * 1. **a ~ a** for all a element of X (reflexive)
  * 2. if **a ~ b** then **b ~ a** (symmetric)
  * 3. if **a ~ b** and **b ~ c** then **a ~ b** (transitive)
- if a, b are elements of Z and n >= 1,  
  * we say *a is congruent to b mod n*
  * and write ```a === b (mod n)```
  * whenever n|b-a
- this is an equivalence relation because
  * 1. a === a (mod n) n|a-a = 0
  * 2. a === b (mod n) n|a-b
  * => n|(-1)a - b = b - a
  * => b === a (mod n)
  * 3. if a === b (mod n) and b === c (mod n)
  * => n|b-a and n|c-b
  * => n|(b-a) + (c-b)
  * => a === c (mod n)
- a === b (mod n) if and only if (a mod n) = (b mod n)
- proof:
```
a = n(q1) + r1 where 0 <= r1 < n
b = n(q2) + r2 where 0 <= r2 < n

if a and b have the same remainder
=> r1 = r2

a - n(q1) = r1 = r2 = b - n(q2)
a = b - n(q2) + n(q1)
a - b = -n(q2 - q1)
b - a = n(q2 - q1)
so n|b-a

in the other direction
n|b-a
b - a = nk
b = a + nk

since a = n(q1) + r1

b = n(q1) + r1 + nk
b = n(q1 + k) + r1
so q2 = q1 + k and r1 = r2.
```
- if a === b (mod n) and d|n then a === b (mod d)
- if a === b (mod n) and c === d (mod n)
  * then a+c == b+d (mod n) and ac === bd (mod n)
- proof of above:
```
   n|b-a and n|d-c
   1. n|(b-a) + (d-c) = (b+d) - (a+c)
   => a+c === b+d (mod n)
   2. n|b-a => b-a=nk and n|d-c => d-c=nl
   => bd = (a+nk)(c+nl) = ac + anl + cnk + nknl
   => bd - ac = n(al + ck + nkl)
   => bd - ac = n(some integer)
   => ac === bd (mod n).
```
-

## Modular Arithmetic

### Finite Groups
- a **group** (S, +) is a set S together with a binary operation + defined on S for which the following properties hold
  * Closure: for all a, b elements of S, we have a + b element of S
  * Identity: there exists and element e of S, called the **identity** of the group, such that e + a = a + e = a for all a element of S
  * Associativity: For all a, b, c elements of S, we have (a+b)+c = a+(b+c)
  * Inverses: for each a element of S, there exists a unique element b of S, called the **inverse** of a, such that a+b=b+a=e

-
