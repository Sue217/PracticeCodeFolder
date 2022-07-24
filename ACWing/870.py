# author: subobo
# created: 24.07.2022 18:42:24

mod = 1000000007

tt = int(input())
primes = dict()
for qq in range(tt):
  n = int(input())
  c = 2
  while c <= n // c:
    while n % c == 0:
      n //= c
      if c not in primes:
        primes[c] = 1
      else:
        primes[c] += 1
    c += 1
  if n > 1:
    if n not in primes:
      primes[n] = 1
    else:
      primes[n] += 1
        
ans = 1
for key in primes:
  ans = ans * (primes[key] + 1) % mod
print(ans)
