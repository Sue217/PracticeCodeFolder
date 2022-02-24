/**
 *    author: subobo
 *    created: 21.02.2022 12:38:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, mod;
  cin >> n >> mod;
  vector<vector<int>> e(n + 1);
  for (int id = 2; id <= n; id++) {
    int fa;
    cin >> fa;
    e[fa].emplace_back(id);
  }
  vector<long long> f(n + 1, 1), g(n + 1, 0), ans(n + 1, 0);
  function<void(int)> Dfs_1 = [&](int u) {
    for (auto v : e[u]) {
      Dfs_1(v);
      f[u] = f[u] * (f[v] + 1) % mod;
    }
  };
  function<void(int)> Dfs_2 = [&](int u) {
    int has = (int) e[u].size();
    if (has == 0) {
      return;
    }
    vector<long long> pre(has + 2, 0), suf(has + 2, 0);
    pre[0] = 1;
    for (int i = 0; i < has; i++) {
      pre[i + 1] = pre[i] * (f[e[u][i]] + 1) % mod;
    }
    suf[has] = 1;
    for (int i = has - 1; i >= 0; i--) {
      suf[i] = suf[i + 1] * (f[e[u][i]] + 1) % mod;
    }
    for (int i = 0; i < has; i++) {
      int v = e[u][i];
      g[v] = pre[i] * suf[i + 1] % mod;
      if (u != 1) {
        g[v] = g[v] * (g[u] + 1) % mod;
      }
    }
    for (auto v : e[u]) {
      ans[v] = f[v] * (g[v] + 1) % mod;
      Dfs_2(v);
    }
  };
  Dfs_1(1);
  Dfs_2(1);
  ans[1] = f[1];
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}