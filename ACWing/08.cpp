/**
 *    author: subobo
 *    created: 11.01.2022 20:57:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, V, M;
  cin >> N >> V >> M;
  vector<vector<int>> dp(V + 1, vector<int>(M + 1));
  for (int i = 1; i <= N; i++) {
    int v, m, w;
    cin >> v >> m >> w;
    for (int j = V; j >= v; j--) {
      for (int k = M; k >= m; k--) {
        dp[j][k] = max(dp[j][k], dp[j - v][k - m] + w);
      }
    }
  }
  cout << dp[V][M] << '\n';
  return 0;
}
