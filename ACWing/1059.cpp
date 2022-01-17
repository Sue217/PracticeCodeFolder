/**
 *    author: subobo
 *    created: 17.01.2022 21:11:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, f;
  cin >> n >> f;
  vector<vector<int>> dp(n + 1, vector<int>(2, -(int)2e9));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + w - f);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - w);
  }
  cout << dp[n][0] << '\n';
  return 0;
}
