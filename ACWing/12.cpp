/**
 *    author: subobo
 *    created: 12.01.2022 21:55:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 3), w(n + 3);
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }
  vector<vector<int>> dp(n + 3, vector<int>(m + 3));
  for (int i = n; i; i--) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[i + 1][j];
      if (j >= v[i]) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
      }
    }
  }
  int j = m;
  for (int it = 1; it <= n; it++) {
    if (j >= v[it] and dp[it][j] == dp[it + 1][j - v[it]] + w[it]) {
      cout << it << " ";
      j -= v[it];
    }
  }
  return 0;
}
