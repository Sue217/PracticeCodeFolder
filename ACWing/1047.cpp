/**
 *    author: subobo
 *    created: 07.04.2022 21:16:15
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
  vector dp(n + 1, vector<int>(m + 1));
  fill(dp[0].begin() + 1, dp[0].end(), -(int) 1e9);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][((j - x) % m + m) % m] + x);
    }
  }
  cout << dp[n][0] << '\n';
  return 0;
}