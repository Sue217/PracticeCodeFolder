n, f = map(int, input().split())

a = [0] * (n + 1)
pref = [0] * (n + 1)

def check(avg):
  for i in range(1, n + 1):
    pref[i] = pref[i - 1] + a[i] - avg
  
  mn = 0
  for i in range(f, n + 1):
    mn = min(mn, pref[i - f])
    if pref[i] - mn >= 0:
      return True

  return False

low = 2000
high = 0

for i in range(1, n + 1):
  a[i] = int(input())
  high = max(high, a[i])
  low = min(low, a[i])

while high - low > 1e-7:
  mid = (high + low) / 2
  if check(mid):
    low = mid
  else:
    high = mid

print(int(high * 1000))
