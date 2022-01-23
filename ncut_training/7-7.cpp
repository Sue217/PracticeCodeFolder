/**
 *    author: subobo
 *    created: 23.01.2022 21:13:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> g[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = max({dp[i][j], dp[i - 1][j] + g[i][j], dp[i - 1][j - 1] + g[i][j]});
    }
  }
  cout << *max_element(dp.back().begin(), dp.back().end()) << '\n';
  return 0;
}