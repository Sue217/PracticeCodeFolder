# author: subobo
# created: 09.09.2022 08:53:55

tt = int(input())
for qq in range(tt):
  n = int(input())
  s = input()
  if n != 5:
    print('NO')
    continue
  if sorted(s) == sorted('Timur'):
    print('YES')
  else:
    print('NO')