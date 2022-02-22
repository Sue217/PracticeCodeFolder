/**
 *    author: subobo
 *    created: 22.02.2022 22:07:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int root = -1;
  vector<vector<int>> e(n + 1);
  vector<int> w(n + 1, 0), v(n + 1, 0);
  for (int id = 1; id <= n; id++) {
    int fa;
    cin >> v[id] >> w[id] >> fa;
    if (fa != -1) {
      e[fa].emplace_back(id);
    } else {
      root = id;
    }
  }
  vector<int> l(n + 1, 0), r(n + 1, 0), Id(n + 1, 0);
  int tot = 0;
  function<void(int)> Dfs = [&](int u) {
    l[u] = ++tot;
    Id[tot] = u;
    for (int v : e[u]) {
      Dfs(v);
    }
    r[u] = tot;
  };
  Dfs(root);
  vector<vector<int>> dp(n + 4, vector<int>(m + 4, 0));
  // fill(dp[n + 1].begin() + 1, dp[n + 1].end(), -(int) 2e9);
  for (int i = n; i >= 1; i--) {
    int u = Id[i];
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[r[u] + 1][j];
      if (j - v[u] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - v[u]] + w[u]);
      }
    }
  }
  cout << dp[1][m] << '\n';
  return 0;
}
