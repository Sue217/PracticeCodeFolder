/**
 *    author: subobo
 *    created: 01.03.2022 21:31:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int id = 1; id <= tt; id++) {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> depth(n + 1);
    for (int i = 2; i <= n; i++) {
      int fa;
      cin >> fa;
      g[fa].push_back(i);
      depth[i] = depth[fa] + 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(2));
    function<void(int)> Dfs = [&](int u) {
      // dp[u][0] = 0;
      dp[u][1] = depth[u];
      for (int v : g[u]) {
        Dfs(v);
        dp[u][1] = min({dp[u][0] + dp[v][1], dp[u][1] + dp[v][0] + 2, dp[u][1] + dp[v][1]});
        dp[u][0] += dp[v][0] + 2;
      }
    };
    Dfs(1);
    cout << "Case #" << id << ": " << min(dp[1][0], dp[1][1]) << '\n';
  }
  return 0;
}