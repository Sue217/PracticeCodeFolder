/**
 *    author: subobo
 *    created: 11.01.2022 13:09:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, V;
  cin >> n >> V;
  vector<int> dp(V + 1);
  for (int i = 1; i <= n; i++) {
    int v, w;
    cin >> v >> w;
    for (int j = v; j <= V; j++) {
      dp[j] = max(dp[j], dp[j - v] + w);
    }
  }
  cout << dp[V] << '\n';
  return 0;
}
