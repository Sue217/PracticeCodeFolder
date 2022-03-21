/**
 *    author: subobo
 *    created: 06.03.2022 18:29:58
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
    int v;
    cin >> v;
    for (int j = m; j >= v; j--) {
      dp[j] = max(dp[j], dp[j - v] + v);
    }
  }
  cout << m - dp[m] << '\n';
  return 0;
}