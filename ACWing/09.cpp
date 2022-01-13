/**
 *    author: subobo
 *    created: 13.01.2022 09:03:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, V;
  cin >> n >> V;
  vector<int> s(V + 1), dp(V + 1);
  vector<vector<int>> w(n + 1, vector<int>(V + 1)), v(n + 1, vector<int>(V + 1));
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    for (int j = 1; j <= s[i]; j++) {
      cin >> v[i][j] >> w[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = V; j >= 0; j--) {
      for (int k = 1; k <= s[i]; k++) {
        if (v[i][k] <= j) {
          dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
        }
      }
    }
  }
  cout << dp[V] << '\n';
  return 0;
}
