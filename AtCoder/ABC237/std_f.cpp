/**
 *    author: subobo
 *    created: 31.01.2022 11:57:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<vector<vector<int>>>> dp(
    n + 1, vector<vector<vector<int>>>(
      m + 2, vector<vector<int>>(
        m + 2, vector<int>(
          m + 2, 0)
      )
    )
  );
  vector<int> cnt(5, 0);
  dp[0][m + 1][m + 1][m + 1] = 1;
  // dp[n][i][j][k]
  constexpr int mod = 998244353;
  for (int id = 1; id <= n; id++) {
    for (int i = 0; i <= m + 1; i++) {
      for (int j = i; j <= m + 1; j++) {
        for (int k = j; k <= m + 1; k++) {
          if (dp[id - 1][i][j][k]) {
            for (int x = 1; x <= m; x++) {
              for(int y = 1; y <= 4; y++) {
                cnt[y] = m + 1;
              }
              cnt[1] = i;
              cnt[2] = j;
              cnt[3] = k;
              int tot = 0;
              for (int t = 1; t <= 3; t++) {
                if (cnt[t] != m + 1) {
                  tot = t;
                }
              }
              if (x > cnt[tot]) {
                cnt[++tot] = x;
              } else {
                int p = 0;
                for (int t = 1; t <= tot; t++) {
                  if (x > cnt[t]) {
                    p = t;
                  }
                }
                cnt[p + 1] = x;
              }
              if (tot <= 3) {
                dp[id][cnt[1]][cnt[2]][cnt[3]] += dp[id - 1][i][j][k];
                dp[id][cnt[1]][cnt[2]][cnt[3]] %= mod;
              }
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      for (int k = j + 1; k <= m; k++) {
        ans += dp[n][i][j][k];
        ans %= mod;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}