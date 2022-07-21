/**
 *    author: subobo
 *    created: 19.07.2022 12:26:59
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
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
    vector<int> v(n + 3);
    vector<int> w(n + 3);
    for (int i = 1; i <= n; i++) {
      cin >> v[i] >> w[i];
    }
    vector<vector<int>> dp(n + 3, vector<int>(m + 3));
    for (int i = n; i >= 1; i--) {
      for (int j = 0; j <= m; j++) {
        dp[i][j] = dp[i + 1][j];
        if (j >= v[i]) {
          dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
      }
    }
    int j = m;
    vector<int> chosen;
    for (int i = 1; i <= n; i++) {
      if (j >= v[i] && dp[i][j] == dp[i + 1][j - v[i]] + w[i]) {
        chosen.push_back(i);
        j -= v[i];
      }
    }
    debug(chosen);
  }
  return 0;
}