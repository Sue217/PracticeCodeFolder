/**
 *    author: subobo
 *    created: 22.02.2022 13:12:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  m += 1;
  vector<vector<int>> e(n + 1);
  vector<int> w(n + 1, 0);
  for (int id = 1; id <= n; id++) {
    int fa;
    cin >> fa >> w[id];
    e[fa].emplace_back(id);
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<int> size(n + 1, 0);
  function<void(int)> Dfs = [&](int u) {
    for (int v : e[u]) {
      Dfs(v);
      vector<int> tmp(n + 1, -(int) 2e9);
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
      dp[u][i] = dp[u][i - 1] + w[u];
    }
  };
  Dfs(0);
  cout << dp[0][m] << '\n';
  return 0;
}
