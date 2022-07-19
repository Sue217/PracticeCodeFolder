# author: subobo
# created: 18.07.2022 23:50:58

tt = int(input())
for qq in range(tt):
  n = int(input())
  a = [input() for i in range(n)]
  st = set(a)
  ans = ''
  for i in range(n):
    ok = True
    for j in range(len(a[i])):
      if a[i][:j] in st and a[i][j:] in st:
        ans += '1'
        ok = False
        break
    if ok:
      ans += '0'
  print(ans)