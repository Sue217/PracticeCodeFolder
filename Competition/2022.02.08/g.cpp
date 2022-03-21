/**
 *    author: subobo
 *    created: 08.02.2022 15:31:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h, d;
  cin >> n >> h >> d;
  vector<vector<int>> dp(n + 4, vector<int>(h + 4, 0)), g(n + 4, vector<int>(h + 4, 0));
  for (int i = 1; i <= n; i++) {
    int tot;
    cin >> tot;
    for (int j = 0; j < tot; j++) {
      int height;
      cin >> height;
      g[i][height] += 1;
    }
  }
  int ans = 0;
  vector<int> get(h + d + 1, 0);
  for (int j = h; j >= 0; j--) {
    for (int i = 1; i <= n; i++) {
      dp[i][j] = dp[i][j + 1];
      dp[i][j] = max(dp[i][j], get[j + d]) + g[i][j];
      get[j] = max(get[j], dp[i][j]);
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
  return 0;
}