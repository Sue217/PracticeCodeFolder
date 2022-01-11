/**
 *    author: subobo
 *    created: 11.01.2022 17:32:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, w;
  cin >> n >> m >> w;
  m--;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i < w; i++) {
    int num, hurt;
    cin >> num >> hurt;
    for (int j = n; j >= num; j--) {
      for (int k = m; k >= hurt; k--) {
        dp[j][k] = max(dp[j][k], dp[j - num][k - hurt] + 1);
      }
    }
  }
  int ma = m;
  while (ma > 0 and dp[n][ma - 1] == dp[n][m]) {
    ma--;
  }
  cout << dp[n][m] << " " << m - ma + 1 << '\n';
  return 0;
}
