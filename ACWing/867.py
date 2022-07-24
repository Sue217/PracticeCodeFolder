# author: subobo
# created: 24.07.2022 15:58:13

def factor(n):
  c = 2
  while c <= n // c:
    if n % c == 0:
      cnt = 0
      while n % c == 0:
        n /= c
        cnt += 1
      print(int(c), cnt)
    c += 1
  if n > 1:
    print(int(n), 1)

tt = int(input())
for qq in range(tt):
  factor(int(input()))
  print()