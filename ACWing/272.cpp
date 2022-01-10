/**
 *    author: subobo
 *    created: 10.01.2022 12:28:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> f(n + 1), g(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    int ma = 1;
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (f[i] == g[j]) {
        dp[i][j] = max(dp[i][j], ma);
      }
      if (f[i] > g[j]) {
        ma = max(ma, dp[i][j] + 1);
      }
  }
    }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, dp[n][i]);
  }
  cout << res << '\n';
  return 0;
}
