/**
 *    author: subobo
 *    created: 11.01.2022 09:38:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int V, n;
  cin >> V >> n;
  vector<int> dp(V + 1);
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    for (int j = V; j >= v; j--) {
      dp[j] = max(dp[j], dp[j - v] + v);
    }
  }
  cout << V - dp[V] << '\n';
  return 0;
}
