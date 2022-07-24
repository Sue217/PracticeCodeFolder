# author: subobo
# created: 24.07.2022 15:26:12

def isprime(n):
  if n < 2:
    return False
  c = 2
  while c <= n // c:
    if n % c == 0:
      return False
    c += 1
  return True


tt = int(input())
for qq in range(tt):
  x = int(input())
  if isprime(x):
    print('Yes')
  else:
    print('No')