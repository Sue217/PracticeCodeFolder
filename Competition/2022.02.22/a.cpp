#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int v, p;
    cin >> v >> p;
    int w = v * p;
    for (int j = n; j >= v; j--) {
      dp[j] = max(dp[j], dp[j - v] + w);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}