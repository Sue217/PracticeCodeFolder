/**
 *    author: subobo
 *    created: 14.01.2022 20:59:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> dp(m + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    for (int j = v; j <= m; j++) {
      dp[j] += dp[j - v];
    }
  }
  cout << dp[m] << '\n';
  return 0;
}
