/**
 *    author: subobo
 *    created: 08.04.2022 14:25:04
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
  vector<set<int>> s(n + 1);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m = accumulate(a.begin(), a.end(), 0);
  vector<vector<bool>> dp(n + 1, vector<bool>(m * 2 + 1));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m * 2; j++) {
      bool ok = dp[i - 1][j];
      if (j >= a[i]) {
        ok = ok || dp[i - 1][j - a[i]];
      }
      if (j + a[i] <= m * 2) {
        ok = ok || dp[i - 1][j + a[i]];
      }
      dp[i][j] = ok;
    }
  }
  int ans = 0;
  for (int i = 1; i <= m * 2; i++) {
    ans += dp[n][i] == true;
  }
  cout << ans << '\n';
  return 0;
}