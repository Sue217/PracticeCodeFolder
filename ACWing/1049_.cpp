/**
 *    author: subobo
 *    created: 17.01.2022 12:28:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = max(dp[i][1], dp[i - 1][0] + a[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
  }
  return 0;
}
