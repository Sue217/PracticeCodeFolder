/**
 *    author: subobo
 *    created: 13.01.2022 22:10:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> master(m + 1);
  vector<vector<pair<int, int>>> slave(m + 1);
  for (int i = 1; i <= m; i++) {
    int v, p, q;
    cin >> v >> p >> q;
    if (q == 0) {
      master[i].first = v; master[i].second = v * p;
    } else {
      slave[q].emplace_back(v, v * p);
    }
  }
  vector<int> dp(n + 1);
  for (int i = 1; i <= m; i++) {
    if (master[i].first) {
      for (int j = n; j >= 0; j--) {
        for (int k = 0; k < (1 << (int) slave[i].size()); k++) {
          int v = master[i].first, w = master[i].second;
          for (int b = 0; b < (int) slave[i].size(); b++) {
            if ((k >> b) & 1) {
              v += slave[i][b].first;
              w += slave[i][b].second;
            }
          }
          if (j >= v) {
            dp[j] = max(dp[j], dp[j - v] + w);
          }
        }
      }
    }
  }
  cout << dp[n] << '\n';
  return 0;
}
