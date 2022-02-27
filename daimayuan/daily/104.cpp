/**
 *    author: subobo
 *    created: 27.02.2022 13:28:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t;
  cin >> n >> m >> t;
  vector<int> u(t), v(t), w(t);
  for (int i = 0; i < t; i++) {
    cin >> u[i] >> v[i] >> w[i];
    swap(u[i], v[i]);
  }
  static constexpr int inf = (int) 2e9;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
  for (int i = 1; i <= n; i++) {
    dp[i][i] = 0;
  }
  for (int i = 0; i < m - 1; i++) {
    vector<vector<int>> tmp(n + 1, vector<int>(n + 1, inf));
    for (int j = 0; j < t; j++) {
      if (u[j] < v[j]) {
        // u < v > next
        for (int k = 1; k < v[j]; k++) {
          tmp[v[j]][min(u[j], k)] = min(tmp[v[j]][min(u[j], k)], dp[u[j]][k] + w[j]);
        }
      } else {
        // u > v < next
        for (int k = v[j] + 1; k <= n; k++) {
          tmp[v[j]][max(u[j], k)] = min(tmp[v[j]][max(u[j], k)], dp[u[j]][k] + w[j]);
        }
      }
    }
    dp = std::move(tmp);
  }
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = min(ans, dp[i][j]);
    }
  }
  if (ans == inf) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}