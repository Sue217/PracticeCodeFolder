# author: subobo
# created: 09.09.2022 09:03:20

tt = int(input())
for qq in range(tt):
  n = int(input())
  row_0 = input()
  row_1 = input()
  ok = True
  for i in range(n):
    if row_0[i] == 'R' and row_1[i] != 'R' or row_0[i] != 'R' and row_1[i] == 'R':
      ok = False
      break
  if ok:
    print("YES")
  else:
    print("NO")