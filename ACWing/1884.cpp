/**
 *    author: subobo
 *    created: 24.01.2022 20:21:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<long long>> dp(n + 1, vector<long long>(3, 0));
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    dp[i][0] = dp[i - 1][0];
    dp[i][1] = dp[i - 1][1];
    dp[i][2] = dp[i - 1][2];
    if (c == 'C') {
      dp[i][0] += 1;
    } else
    if (c == 'O') {
      dp[i][1] += dp[i - 1][0];
    } else
    if (c == 'W') {
      dp[i][2] += dp[i - 1][1];
    }
  }
  cout << dp[n][2] << '\n';
  return 0;
}
