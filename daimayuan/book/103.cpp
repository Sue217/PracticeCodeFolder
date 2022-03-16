/**
 *    author: subobo
 *    created: 16.03.2022 11:37:37
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
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  const int inf = (int) 1e9;
  const int N = 1 << n;
  vector<vector<int>> dp(N, vector<int>(n, inf));
  dp[1][0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      if (i >> j & 1) {
        for (int k = 0; k < n; k++) {
          if (k != j && i >> k & 1) {
            dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + g[k][j]);
          }
        }
      }
    }
  }
  cout << dp[N - 1][n - 1] << '\n';
  return 0;
}