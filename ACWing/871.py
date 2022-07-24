# author: subobo
# created: 24.07.2022 19:42:15

mod = 1000000007
primes = {}

tt = int(input())
for qq in range(tt):
  n = int(input())
  c = 2
  while c <= n // c:
    while n % c == 0:
      n //= c
      if c in primes:
        primes[c] += 1
      else:
        primes[c] = 1
    c += 1
  if n > 1:
    if n in primes:
      primes[n] += 1
    else:
      primes[n] = 1
  
ans = 1
# for prime in primes:
#   exp = primes[prime]
#   k = 1
#   for _ in range(exp):
#     k = (k * prime + 1) % mod
#   ans = ans * k % mod

for prime in primes:
  exp = primes[prime] + 1
  ans = ans * (1 - prime**exp) // (1 - prime) % mod
print(ans)