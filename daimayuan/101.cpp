/**
 *    author: subobo
 *    created: 18.02.2022 12:11:35
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
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<int> size(n + 1, 0);
  function<void(int)> Dfs = [&](int u) {
    vector<int> tmp(n + 1, -(int) 2e9);
    for (int v : e[u]) {
      Dfs(v);
      for (int i = 0; i <= size[u]; i++) {
	      for (int j = 0; j <= size[v]; j++) {
	        tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j]);
	      }
      }
      size[u] += size[v];
      for (int i = 0; i <= size[u]; i++) {
        dp[u][i] = tmp[i];
      }
    }
    size[u] += 1;
    for (int i = size[u]; i >= 1; i--) {
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