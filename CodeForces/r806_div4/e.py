# author: subobo
# created: 19.07.2022 09:29:41

tt = int(input())
for qq in range(tt):
  n = int(input())
  a = [input() for i in range(n)]
  ans = 0
  for i in range(n // 2):
    for j in range((n + 1) // 2):
      sum = int(a[i][j]) + int(a[n - 1 - j][i]) + int(a[j][n - 1 - i]) + int(a[n - 1 - i][n - 1 - j])
      ans += min(sum, 4 - sum)
  print(ans)