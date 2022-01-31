/**
 *    author: subobo
 *    created: 31.01.2022 13:01:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  constexpr int mod = 998244353;
  vector<vector<vector<vector<int>>>> dp(
    n + 1, vector<vector<vector<int>>> (
      m + 1, vector<vector<int>> (
        m + 2, vector<int> (
          m + 3, 0
        )
      )
    )
  );
  dp[0][m][m + 1][m + 2] = 1;
  for (int id = 1; id <= n; id++) {
    for (int i = 0; i <= m; i++) {
      for (int j = i; j <= m + 1; j++) {
        for (int k = j; k <= m + 2; k++) {
          for (int x = 0; x < m; x++) {
            if (x <= i) {
              dp[id][x][j][k] += dp[id - 1][i][j][k];
              dp[id][x][j][k] %= mod;
            } else
            if (x <= j) {
              dp[id][i][x][k] += dp[id - 1][i][j][k];
              dp[id][i][x][k] %= mod;
           } else
            if (x <= k) {
              dp[id][i][j][x] += dp[id - 1][i][j][k];
              dp[id][i][j][x] %= mod;
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        ans += dp[n][i][j][k];
        ans %= mod;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}