/**
 *    author: subobo
 *    created: 16.01.2022 21:56:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> dp(n + 1, -(int)2e9), cutting{a, b, c};
  dp[0] = 0;
  for (auto seg : cutting) {
    for (int i = seg; i <= n; i++) {
      dp[i] = max(dp[i], dp[i - seg] + 1);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}