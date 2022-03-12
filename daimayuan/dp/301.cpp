/**
 *    author: subobo
 *    created: 11.03.2022 11:59:09
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
  int n, L, R;
  while (cin >> n >> L >> R) {
    vector<int> s(1, 0);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s.push_back(a + s.back());
    }
    constexpr int inf = (int) 1e9;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, inf)));
    for (int len = 0; len <= n; len++) {
      for (int l = 1; l + len <= n; l++) {
        int r = l + len;
        if (l == r) {
          dp[l][r][1] = 0;
          continue;
        }
        for (int p = 2; p <= n; p++) {
          for (int m = l; m < r; m++) {
            dp[l][r][p] = min(dp[l][r][p], dp[l][m][1] + dp[m + 1][r][p - 1]);
          }
          if (L <= p && p <= R) {
            dp[l][r][1] = min(dp[l][r][p], dp[l][r][1]);
          }
        }
        dp[l][r][1] += s[r] - s[l - 1];
      }
    }
    int ans = dp[1][n][1];
    cout << (ans >= inf ? 0 : ans) << '\n';
  }
  return 0;
}