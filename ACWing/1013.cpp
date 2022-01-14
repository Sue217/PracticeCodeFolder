/**
 *    author: subobo
 *    created: 13.01.2022 15:23:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> w(n + 1, vector<int>(m + 1)), dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> w[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i - 1][j];
      for (int k = 0; k <= j; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + w[i][k]);
      }
    }
  }
  cout << dp[n][m] << '\n';
  int k = m;
  vector<pair<int, int>> res;
  for (int i = n; i; i--) {
    for (int j = 0; j <= k; j++) {
      if (dp[i][k] == dp[i - 1][k - j] + w[i][j]) {
        res.emplace_back(i, j);
        k -= j;
        break;
      }
    }
  }
  for (auto it : res) {
    cout << it.first << " " << it.second << '\n';
  }
  return 0;
}
