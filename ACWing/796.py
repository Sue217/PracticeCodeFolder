# author: Jingbo Su
# created: 16.05.2022 15:02:06

import io
import os
import sys

if __name__ == '__main__':
  n, m, q = map(int, input().split())
  a = [[0] * (m + 1)]
  a += [[0] + list(map(int, input().split())) for i in range(n)]
  pref = [[0] * (m + 1) for i in range(n + 1)]
  for i in range(1, n + 1):
    for j in range(1, m + 1):
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j]
  while q > 0:
    q -= 1
    x1, y1, x2, y2 = map(int, input().split())
    print(pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1])
