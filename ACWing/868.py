# author: subobo
# created: 24.07.2022 16:44:32

# def sieve(n):
#   used = [False] * (n + 1)
#   primes = []
#   for c in range(2, n + 1):
#     if not used[c]:
#       primes.append(c)
#       d = c
#       while d <= n:
#         used[d] = True
#         d += c
#   return len(primes)
  
# print(sieve(int(input())))

def sieve(n):
  least = [0] * (n + 1)
  primes = []
  for c in range(2, n + 1):
    if least[c] == 0:
      least[c] = c
      primes.append(c)
      
    for x in primes:
      if x > least[c] or c * x > n:
        break
      least[c * x] = c
  return len(primes)
      
print(sieve(int(input())))