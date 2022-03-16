/**
 *    author: subobo
 *    created: 16.03.2022 14:06:59
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
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  vector<int> d1(n), d2(n);
  function<void(int)> Dfs = [&](int v) {
    for (int u : g[v]) {
      Dfs(u);
      if (a[v] == (a[u] + 1) % 3) {
        d1[v] = max(d1[v], d1[u]);
      }
      if (a[u] == (a[v] + 1) % 3) {
        d2[v] = max(d2[v], d2[u]);
      }
    }
    ans = max(ans, d1[v] + d2[v] + 1);
    d1[v] += 1;
    d2[v] += 1;
  };
  Dfs(0);
  cout << ans << '\n';
  return 0;
}