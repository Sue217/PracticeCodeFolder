/**
 *    author: subobo
 *    created: 28.01.2022 14:22:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> balls(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    cin >> balls[i];
    balls[i + n] = balls[i];
  }
  vector<vector<int>> dp(n * 3, vector<int>(n * 3));
  for (int len = 3; len <= n + 1; len++) {
    for (int l = 1; l + len - 1 <= n * 2; l++) {
      int r = l + len - 1;
      for (int m = l + 1; m < r; m++) {
        dp[l][r] = max(dp[l][r], dp[l][m] + dp[m][r] + balls[l] * balls[m] * balls[r]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i][i + n]);
  }
  cout << ans << '\n';
  return 0;
}