/**
 *    author: subobo
 *    created: 12.01.2022 15:44:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  array<int, 4> price{10, 20, 50, 100};
  for (auto p : price) {
    for (int i = p; i <= n; i++) {
      dp[i] += dp[i - p];
    }
  }
  cout << dp[n] << '\n';
  return 0;
}
