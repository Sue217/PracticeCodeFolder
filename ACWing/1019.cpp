/**
 *    author: subobo
 *    created: 12.01.2022 15:05:49
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
    for (int j = m; j >= v; j--) {
      for (int k = 0; k <= s and k * v <= j; k++) {
        dp[j] = max(dp[j], dp[j - v * k] + w * k);
      }
    }
  }
  cout << dp[m] << '\n';
  return 0;
}
