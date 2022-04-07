/**
 *    author: subobo
 *    created: 06.04.2022 10:17:50
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = dp[i][j - 1];
        if (i >= j) {
          dp[i][j] += dp[i - j][j];
        }
      }
    }
    cout << dp[n][m] << '\n';
  }
  return 0;
}