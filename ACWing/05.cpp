/**
 *    author: subobo
 *    created: 12.01.2022 15:17:50
**/
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, V;
  cin >> n >> V;
  vector<pii> pack;
  for (int i = 1; i <= n; i++) {
    int v, w, s;
    cin >> v >> w >> s;
    for (int j = 1; j <= s; j++) {
      s -= j;
      pack.emplace_back(j * v, j * w);
    }
    if (s) {
      pack.emplace_back(s * v, s * w);
    }
  }
  vector<int> dp(V + 1);
  for (auto it : pack) {
    for (int j = V; j >= it.first; j--) {
      dp[j] = max(dp[j], dp[j - it.first] + it.second);
    }
  }
  cout << dp[V] << '\n';
  return 0;
}
