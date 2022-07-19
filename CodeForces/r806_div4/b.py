# author: subobo
# created: 18.07.2022 23:19:35

tt = int(input())
for qq in range(tt):
  n = int(input())
  s = str(input())
  dic = set()
  ans = 0
  for i in range(len(s)):
    if s[i] not in dic:
      ans += 2
      dic.add(s[i])
    else:
      ans += 1
  print(ans)
  
"""
tt = int(input())
for qq in range(tt):
  n = int(input())
  print(n + len(input()))
"""