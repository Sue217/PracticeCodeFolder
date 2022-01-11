/**
 *    author: subobo
 *    created: 11.01.2022 14:24:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, V;
  cin >> n >> V;
  vector<int> v(n + 1), w(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i] >> s[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(V + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= V; j++) {
      for (int k = 0; k <= s[i] && k * v[i] <= j; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
      }
    }
  }
  cout << dp[n][V] << '\n';
  return 0;
}
