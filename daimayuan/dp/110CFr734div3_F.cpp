/**
 *    author: subobo
 *    created: 02.03.2022 15:11:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    constexpr int inf = (int) 1e9, mod = inf + 7;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, inf));
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[u][v] = g[v][u] = 1;
    }
    if (m == 2) {
      cout << n * (n - 1) / 2 << '\n';
      continue;
    }
    // Floyd
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) {
          g[i][j] = 0;
        }
      }
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    long long ans = 0;
    for (int pv = 1; pv <= n; pv++) {
      for (int d = 1; d <= n; d++) {
        vector<long long> cnt(n + 1);
        for (int u = 1; u <= n; u++) {
          if (g[pv][u] == d) {
            for (int v = 1; v <= n; v++) {
              if (g[pv][v] == 1 && g[pv][u] == g[pv][v] + g[v][u]) {
                cnt[v] += 1;
              }
            }
          }
        }
        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
          if (cnt[i] != 0) {
            for (int j = m; j >= 1; j--) {
              dp[j] = (dp[j] + dp[j - 1] * cnt[i]) % mod;
            }
          }
        }
        ans = (ans + dp[m]) % mod;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}