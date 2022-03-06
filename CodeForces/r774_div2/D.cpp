/**
 *    author: subobo
 *    created: 05.03.2022 21:10:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n == 2) {
    cout << 2 << " " << 2 << '\n';
    cout << 1 << " " << 1 << '\n';
    return 0;
  }
  vector dp(n + 1, vector<int>(2)), w(n + 1, vector<int>(2));
  function<void(int, int)> Dfs = [&](int v, int pv) {
    // dp[v][0] = 0;
    w[v][0] = 1;
    dp[v][1] = 1;
    w[v][1] = (int) g[v].size();
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      Dfs(u, v);
      dp[v][1] += dp[u][0];
      w[v][1] += w[u][0];
      if (dp[u][0] > dp[u][1]) {
        dp[v][0] += dp[u][0];
        w[v][0] += w[u][0];
      } else {
        dp[v][0] += dp[u][1];
        w[v][0] += w[u][1];
      }
    }
  };
  Dfs(1, 0);
  vector<int> ans(n + 1);
  function<void(int, int, int)> dfs_ans = [&](int v, int pv, int get) {
    ans[v] = get;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      if (get == 1) {
        dfs_ans(u, v, 0);
      } else
      if (dp[u][0] > dp[u][1]) {
        dfs_ans(u, v, 0);
      } else {
        dfs_ans(u, v, 1);
      }
    }
  };
  if (dp[1][0] > dp[1][1]) {
    cout << dp[1][0] << " " << w[1][0] << '\n';
    dfs_ans(1, 0, 0);
  } else {
    cout << dp[1][1] << " " << w[1][1] << '\n';
    dfs_ans(1, 0, 1);
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) {
      cout << 1 << " \n"[i == n];
    } else {
      cout << g[i].size() << " \n"[i == n];
    }
  }
  return 0;
}