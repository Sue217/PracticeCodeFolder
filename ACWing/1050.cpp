/**
 *    author: subobo
 *    created: 05.04.2022 13:07:30
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
    vector dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int k = i; k <= n; k++) {
          dp[j][k] += dp[j - 1][k - i];
        }
      }
    }
    cout << dp[m][n] << '\n';
  }
  return 0;
}