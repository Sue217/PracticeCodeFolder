# author: Jingbo Su
# created: 16.05.2022 14:48:36

import io
import os
import sys

if __name__ == '__main__':
  n, m = map(int, input().split())
  a = list(map(int, input().split()))
  pref = [0] * n
  for i in range(len(a)):
    if i == 0:
      pref[i] = a[i]
    else:
      pref[i] = pref[i - 1] + a[i]
  while m > 0:
    m -= 1
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    if (l == 0):
      print(pref[r])
    else:
      print(pref[r] - pref[l - 1])
