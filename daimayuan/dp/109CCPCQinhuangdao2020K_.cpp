/**
 *    author: subobo
 *    created: 02.03.2022 11:43:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int id = 1; id <= tt; id++) {
    int n;
    cin >> n;
    vector<int> fa(n + 1), dep(n + 1);  
    for (int i = 2; i <= n; i++) {
      cin >> fa[i];
      dep[i] = dep[fa[i]] + 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) {
      dp[i][1] = dep[i];
      // dp[i][0] = 0;
    }
    for (int v = n; v >= 2; v--) {
      int pv = fa[v];
      dp[pv][1] = min({dp[pv][0] + dp[v][1], dp[pv][1] + dp[v][0] + 2, dp[pv][1] + dp[v][1]});
      dp[pv][0] += dp[v][0] + 2;
    }
    cout << "Case #" << id << ": " << min(dp[1][0], dp[1][1]) << '\n';
  }
  return 0;
}