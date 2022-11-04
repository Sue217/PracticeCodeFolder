n, r = map(int, input().split())

N = 5002
r = min(r, N)
pref = [[0] * N] * N

for _ in range(n):
  x, y, w = map(int, input().split())
  x += 1
  y += 1
  pref[x][y] += w

for i in range(1, N):
  for j in range(1, N):
    pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]

ans = -1
for i in range(r, N):
  for j in range(r, N):
    ans = max(ans, pref[i][j] - pref[i - r][j] - pref[i][j - r] + pref[i - r][j - r])

print(ans)
