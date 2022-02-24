/**
 *    author: subobo
 *    created: 18.02.2022 14:23:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> e(n + 1);
  vector<int> a(n + 1, 0);
  for (int id = 2; id <= n; id++) {
    int fa;
    cin >> fa;
    e[fa].emplace_back(id);
  }
  for (int id = 1; id <= n; id++) {
    cin >> a[id];
  }
  static constexpr int M = 100;
  vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
  vector<int> size(n + 1, 0);
  function<void(int)> Dfs = [&](int u) {
    vector<int> tmp(M + 1, -(int) 2e9);
    for (int v : e[u]) {
      Dfs(v);
      for (int i = 0; i <= min(M, size[u]); i++) {
        for (int j = 0; j <= size[v] && i + j <= M; j++) {
          tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
        }
      }
      size[u] += size[v];
      for (int i = 0; i <= min(M, size[u]); i++) {
        dp[u][i] = tmp[i];
      }
    }
    size[u] += 1;
    for (int i = min(M, size[u]); i >= 1; i--) {
      dp[u][i] = dp[u][i - 1] + a[u];
    }
  };
  Dfs(1);
  for (int i = 0; i < q; i++) {
    int u, m;
    cin >> u >> m;
    cout << dp[u][m] << '\n';
  }
  return 0;
}