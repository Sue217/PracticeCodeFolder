#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m;
  cin >> m;
  vector<int> dp(m + 1, (int) 2e9);
  dp[0] = 0;
  for (int i = 1; i < 20; i++) {
    for (int j = i * i * i * i; j <= m; j++) {
      dp[j] = min(dp[j], dp[j - i * i * i * i] + 1);
    }
  }
  // assert(dp[m] != 0);
  cout << dp[m] << '\n';
  return 0;
}