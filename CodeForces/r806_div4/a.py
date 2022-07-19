# author: subobo
# created: 18.07.2022 23:10:42

tt = int(input())
for qq in range(tt):
  s = str(input())
  if s.lower() == 'yes':
    print('YES')
  else:
    print('NO')

"""
The input takes input from the user but does not read escape character.
The readline() also takes input from the user but also reads the escape character.
"""