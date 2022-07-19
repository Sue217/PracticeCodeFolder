# author: subobo
# created: 18.07.2022 23:34:59

from sys import stdin, stderr

tt = int(input())
for qq in range(tt):
  n = int(input())
  a = list(map(int, input().split()))
  for i in range(n):
    m, s = input().split()
    times = 0
    for j in range(int(m)):
      if s[j] == 'D':
        times += 1
      else:
        times -= 1
    print((a[i] + times) % 10, end=" ")
  print()