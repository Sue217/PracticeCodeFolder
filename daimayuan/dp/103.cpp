/**
 *    author: subobo
 *    created: 18.02.2022 17:07:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> e(n + 1);
  vector<int> a(n + 1, 0), w(n + 1, 0);
  for (int id = 2; id <= n; id++) {
    int fa;
    cin >> fa;
    e[fa].emplace_back(id);
  }
  for (int id = 1; id <= n; id++) {
    cin >> a[id];
  }
  for (int id = 1; id <= n; id++) {
    cin >> w[id];
  }
  int tot = 0;
  vector<int> l(n + 1, 0), r(n + 1, 0), Id(n + 1, 0);
  function<void(int)> Dfs = [&](int u) {
    l[u] = ++tot;
    Id[tot] = u;
    for (int v : e[u]) {
      Dfs(v);
    }
    r[u] = tot;
  };
  Dfs(1);
  vector<vector<int>> dp(n + 4, vector<int>(m + 4, 0));
  fill(dp[n + 1].begin() + 1, dp[n + 1].end(), -(int) 2e9);
  for (int i = n; i >= 1; i--) {
    int u = Id[i];
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[r[u] + 1][j];
      if (j - w[u] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - w[u]] + a[u]);
      }
    }
  }
  for (int id = 0; id <= m; id++) {
    cout << (dp[1][id] >= 0 ? dp[1][id] : 0) << '\n';
  }
  return 0;
}