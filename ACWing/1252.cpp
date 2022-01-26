/**
 *    author: subobo
 *    created: 26.01.2022 11:05:29
**/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 10007;

int v[maxn], w[maxn], p[maxn], dp[maxn];

inline int get(int x) {
  return (x == p[x] ? x : (p[x] = get(p[x])));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, V;
  cin >> n >> m >> V;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    cin >> v[i] >> w[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    x = get(x); y = get(y);
    if (x != y) {
      p[x] = y;
      v[y] += v[x];
      w[y] += w[x];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] == i) {
      for (int j = V; j >= v[i]; j--) {
        dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
      }
    }
  }
  cout << dp[V] << '\n';
  return 0;
}