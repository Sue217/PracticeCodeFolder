/**
 *    author: subobo
 *    created: 10.01.2022 12:28:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    int ma = 1;
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j];
      if (a[i] == b[j]) {
        dp[i][j] = ma;
      }
      if (a[i] > b[j]) {
        ma = max(ma, dp[i - 1][j] + 1);
      }
    }
  }
  cout << *max_element(dp.back().begin(), dp.back().end()) << '\n';
  return 0;
}
