n = int(input())

a = [0] * (n + 3)
b = [0] * (n + 3)

for i in range(1, n + 1):
  a[i] = int(input())
  b[i] = a[i] - a[i - 1]

positive = 0
negative = 0

for i in range(2, n + 1):
  if b[i] > 0:
    positive += b[i]
  if b[i] < 0:
    negative -= b[i]

print(max(positive, negative))
print(abs(positive - negative) + 1)
