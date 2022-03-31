/**
 *    author: subobo
 *    created: 31.03.2022 16:18:32
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
  dp[1][1] = 1;
  array<int, 2> dx{0, 1}, dy{1, 0};
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= m; y++) {
      if (x % 2 == 0 && y % 2 == 0) {
        continue;
      }
      for (int d = 0; d < 2; d++) {
        int xx = x + dx[d];
        int yy = y + dy[d];
        if (xx > n || yy > m || xx % 2 == 0 && yy % 2 == 0) {
          continue;
        }
        dp[xx][yy] += dp[x][y];
      }
    }
  }
  cout << dp[n][m] << '\n';
  return 0;
}