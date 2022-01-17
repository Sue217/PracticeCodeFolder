/**
 *    author: subobo
 *    created: 17.01.2022 15:54:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(m + 1, vector<int>(2, -(int)2e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    for (int j = m; j >= 1; j--) {
      dp[j][0] = max(dp[j][0], dp[j][1] + w);
      dp[j][1] = max(dp[j][1], dp[j - 1][0] - w);
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = max(ans, dp[i][0]);
  }
  cout << ans << '\n';
  return 0;
}
