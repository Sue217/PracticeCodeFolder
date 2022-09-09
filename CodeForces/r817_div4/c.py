# author: subobo
# created: 09.09.2022 09:09:41

tt = int(input())
for qq in range(tt):
  n = int(input())
  dic = {}
  l1 = input().split()
  l2 = input().split()
  l3 = input().split()
  for i in range(n):
    if l1[i] in dic:
      dic[l1[i]] += 1
    else:
      dic[l1[i]] = 1
    if l2[i] in dic:
      dic[l2[i]] += 1
    else:
      dic[l2[i]] = 1
    if l3[i] in dic:
      dic[l3[i]] += 1
    else:
      dic[l3[i]] = 1
      
  score = [0] * 3
  for i in range(n):
    if dic[l1[i]] == 1:
      score[0] += 3
    elif dic[l1[i]] == 2:
      score[0] += 1
    if dic[l2[i]] == 1:
      score[1] += 3
    elif dic[l2[i]] == 2:
      score[1] += 1
    if dic[l3[i]] == 1:
      score[2] += 3
    elif dic[l3[i]] == 2:
      score[2] += 1
  print(score[0], score[1], score[2])