/**
 *    author: subobo
 *    created: 28.01.2022 10:40:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> presum(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    presum[i] = presum[i - 1] + x;
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      dp[l][r] = (int) 2e9;
      int last = presum[r] - presum[l - 1];
      for (int m = l; m < r; m++) {
        dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r] + last);
      }
    }
  }
  cout << dp[1][n] << '\n';
  return 0;
}