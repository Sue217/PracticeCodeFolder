# author: subobo
# created: 09.09.2022 09:32:54

tt = int(input())
for qq in range(tt):
  n = int(input())
  s = input()
  sum = 0
      
  ans = []
  for i in range(n):
    if s[i] == 'L':
      sum += i
      ans.append(max(0, (n - i - 1) - i))
    else:
      sum += (n - i - 1)
      ans.append(max(i - (n - i - 1), 0))

  ans.sort(reverse=True)
  for o in ans:
    sum += o
    print(sum, end=' ')
  print()
  