/**
 *    author: subobo
 *    created: 15.01.2022 17:53:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> dp(m + 1);
  for (int i = 1; i <= n; i++) {
    int v, w, s;
    cin >> v >> w >> s;
    if (s == 0) {
      for (int j = v; j <= m; j++) {
        dp[j] = max(dp[j], dp[j - v] + w);
      }
    } else {
      if (s == -1) {
        s = 1;
      }
      for (int k = 1; k <= s; k <<= 1) {
        for (int j = m; j >= k * v; j--) {
          dp[j] = max(dp[j], dp[j - k * v] + k * w);
        }
        s -= k;
      }
      if (s) {
        for (int j = m; j >= s * v; j--) {
          dp[j] = max(dp[j], dp[j - s * v] + s * w);
        }
      }
    }
  }
  cout << dp[m] << '\n';
  return 0;
}
