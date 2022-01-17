/**
 *    author: subobo
 *    created: 17.01.2022 21:01:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(3, -(int)2e9));
  dp[0][1] = dp[0][2] = 0;
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - w);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + w);
    dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
  }
  cout << max(dp[n][1], dp[n][2]) << '\n';
  return 0;
}
