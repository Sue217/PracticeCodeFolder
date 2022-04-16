# 状态压缩DP

## 子集和

Give an array $f\ [0, 1, ..., 2^n-1]$

Ask an array $g$, and $g_i=\sum_{i\&j=j}f_j$

$if.\ i_{bit}=0,j_{bit}=0$

eg. `i[101]: j{[000], [001], [100], [101]}`

### 1. 暴力枚举 $O(4^n)$

```cpp
for (int i = 0; i < pow(2, n); i++)
  for (int j = 0; j < pow(2, n); j++)
    if (i & j == j)
      g[i] += f[j];
```

### 2. 枚举子集 $O(3^n)$

`i[001001]: j{[000000], [000001], [001000], [001001]}`

可以发现 f[i] 中有 k 个 1，其子集个数有 $2^k$

$result=\sum_{k=0}^n(^n_k)·2^k=3^n$

二项式定理：$(a+b)^n=(^n_k)a^kb^{(n-k)}\ (let\ a=2,b=1)$

每一独立位：(total = 3)

```cpp
i = 1: j = {0 / 1}
i = 0: j = {0}
```

code

```cpp
for (int i = 0; i < (1 << n); i++) {
  int j = i;
  while (j > 0) {
    g[i] += f[j];
    j = (j - 1) & i;
  }
}
```

### 3. 高维前缀和 $O(n2^n)$

```cpp
for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++)
    for (int k = 1; k <= n; k++)
      pref[i][j][k] += pref[i][j][k - 1];

for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++)
    for (int k = 1; k <= n; k++)
      pref[i][j][k] += pref[i][j - 1][k];

for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j++)
    for (int k = 1; k <= n; k++)
      pref[i][j][k] += pref[i - 1][j][k];
```

n-D array with 2 numbers on each bit

```cpp
for (int i = 0; i < n; i++)
  for (int j = 0; j < (1 << n); j++)
    if (j << i & 1)
      f[j] += f[j - (1 << n)];
```

