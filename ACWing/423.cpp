/**
 *    author: subobo
 *    created: 11.01.2022 08:59:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, m;
  cin >> t >> m;
  vector<int> dp(t + 1);
  // zero-one-pack
  // max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i])
  for (int i = 0; i < m; i++) {
    int tt, vv;
    cin >> tt >> vv;
    for (int j = t; j >= tt; j--) {
      dp[j] = max(dp[j], dp[j - tt] + vv);
    }
  }
  cout << dp[t] << '\n';
  return 0;
}
