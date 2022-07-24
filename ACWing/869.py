# author: subobo
# created: 24.07.2022 18:28:29

def factor(n):
  a = []
  c = 1
  while c <= n // c:
    if n % c == 0:
      a.append(c)
      if c != n / c:
        a.append(n // c)
    c += 1
  a.sort()
  print(" ".join(map(str, a)))

tt = int(input())
for qq in range(tt):
  factor(int(input()))