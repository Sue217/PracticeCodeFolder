/**
 *    author: subobo
 *    created: 21.04.2022 21:33:55
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = n;
  vector<int> sum(n);
  function<void(int, int)> Dfs = [&](int u, int v) {
    if (v >= ans) return;
    if (u == n) {
      ans = v;
      return;
    }
    for (int i = 0; i < v; i++) {
      if (sum[i] + a[u] <= w) {
        sum[i] += a[u];
        Dfs(u + 1, v);
        sum[i] -= a[u];
      }
    }
    sum[v] += a[u];
    Dfs(u + 1, v + 1);
    sum[v] -= a[u];
  };
  sort(a.rbegin(), a.rend());
  Dfs(0, 0);
  cout << ans << '\n';
  return 0;
}