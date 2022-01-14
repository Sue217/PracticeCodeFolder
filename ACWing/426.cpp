/**
 *    author: subobo
 *    created: 14.01.2022 08:45:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> dp(m + 1);
  for (int i = 1; i <= n; i++) {
    int v, w;
    cin >> v >> w;
    for (int j = m; j >= v; j--) {
      dp[j] = max(dp[j], dp[j - v] + w * v);
    }
  }
  cout << dp[m] << '\n';
  return 0;
}
