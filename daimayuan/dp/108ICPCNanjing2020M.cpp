/**
 *    author: subobo
 *    created: 01.03.2022 15:58:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) {
      int fa;
      cin >> fa;
      g[fa].push_back(i);
    }
    vector<int> hp(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> hp[i];
    }
    static constexpr long long inf = (long long) 1e18;
    vector dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2)));
    vector<int> size(n + 1);
    function<void(int)> Dfs = [&](int u) {
      size[u] = 1;
      dp[u][0][0] = hp[u];
      dp[u][1][0] = inf;
      dp[u][0][1] = inf;
      // dp[u][1][1] = 0;
      for (int v : g[u]) {
        Dfs(v);
        vector tmp(n + 1, vector<long long>(2, inf));
        for (int i = 0; i <= size[u]; i++) {
          for (int j = 0; j <= size[v]; j++) {
            tmp[i + j][0] = min({tmp[i + j][0], dp[u][i][0] + dp[v][j][0] + hp[v], dp[u][i][0] + dp[v][j][1]});
            tmp[i + j][1] = min({tmp[i + j][1], dp[u][i][1] + dp[v][j][0], dp[u][i][1] + dp[v][j][1]});
          }
        }
        size[u] += size[v];
        for (int i = 0; i <= size[u]; i++) {
          dp[u][i][0] = tmp[i][0];
          dp[u][i][1] = tmp[i][1];
        }
      }
    };
    Dfs(1);
    for (int i = 0; i <= n; i++) {
      cout << min(dp[1][i][0], dp[1][i][1]) << " \n"[i == n];
    }
  }
  return 0;
}