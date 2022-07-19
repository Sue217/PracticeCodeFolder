# author: subobo
# created: 19.07.2022 10:43:12

tt = int(input())
for qq in range(tt):
  n = int(input())
  a = [0]
  a.extend(list(map(int, input().split())))
  
  pref = [0] * (n + 1)
  for i in range(1, n + 1):
    pref[i] = pref[i - 1] + int(a[i] < i)
  
  ans = 0
  for j in range(1, n + 1):
    if a[j] < j and a[j] - 1 >= 1:
      ans += pref[a[j] - 1]

  print(ans)