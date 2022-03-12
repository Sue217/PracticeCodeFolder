/**
 *    author: subobo
 *    created: 27.02.2022 22:47:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<long long>> dp(n + 4, vector<long long>(3));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i + 1][0] += dp[i][j];
      if (j < 2) {
        dp[i + 2][j + 1] += dp[i][j];
      }
    }
  }
  long long ans = dp[n][0] + dp[n][1] + dp[n][2];
  cout << ans << '\n';
  return 0;
}