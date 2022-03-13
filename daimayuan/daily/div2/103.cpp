/**
 *    author: subobo
 *    created: 13.03.2022 08:32:09
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j <= m; j++) {
      if (dp[i - 1][j] == 1) {
        dp[i][j + a] = 1;
        dp[i][j + b] = 1;
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    cout << dp[n][i];
  }
  cout << '\n';
  return 0;
}