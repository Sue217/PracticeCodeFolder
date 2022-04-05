#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int k = i; k <= n; k++) {
          dp[j][k] += dp[j - 1][k - i];
        }
      }
    }
    cout << dp[m][i] << '\n';
  }
  return 0;
}