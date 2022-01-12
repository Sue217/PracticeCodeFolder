/**
 *    author: subobo
 *    created: 12.01.2022 09:48:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, w;
  cin >> n >> m >> w;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, (int)2e9));
  dp[0][0] = 0;
  for (int i = 0; i < w; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int j = n; j >= 0; j--) {
      for (int k = m; k >= 0; k--) {
        dp[j][k] = min(dp[j][k], dp[max(0, j - a)][max(0, k - b)] + c);
      }
    }
  }
  cout << dp[n][m] << '\n';
  return 0;
}
