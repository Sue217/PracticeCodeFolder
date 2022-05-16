# author: Jingbo Su
# created: 13.05.2022 23:33:02

import io
import os
import sys

def merge(l, r, a):
  if l >= r:
    return 0
  mid = (l + r) >> 1
  ans = merge(l, mid, a) + merge(mid + 1, r, a)
  b = []
  low = l
  high = mid + 1
  while low <= mid and high <= r:
    if a[low] <= a[high]:
      b.append(a[low])
      low += 1
    else:
      b.append(a[high])
      ans += mid - low + 1
      high += 1
  while low <= mid:
    b.append(a[low])
    low += 1
  while high <= r:
    b.append(a[high])
    high += 1
  it = l
  for x in b:
    a[it] = x
    it += 1
  return ans

if __name__ == '__main__':
  n = int(input())
  a = list(map(int, input().split()))
  ans = merge(0, n - 1, a)
  print(ans)