/**
 *    author: subobo
 *    created: 28.01.2022 15:52:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<size_t> node(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> node[i];
  }
  vector<vector<size_t>> dp(n + 1, vector<size_t>(n + 1));
  for (int len = 3; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      dp[l][r] = (size_t) 2e31;
      for (int m = l + 1; m < r; m++) {
        dp[l][r] = min(dp[l][r], dp[l][m] + dp[m][r] + node[l] * node[m] * node[r]);
      }
    }
  }
  cout << dp[1][n] << '\n';
  return 0;
}