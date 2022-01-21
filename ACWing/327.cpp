/**
 *    author: subobo
 *    created: 21.01.2022 20:39:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int T = 1 << m, mod = (int) 1e8;
  vector<int> g(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int t;
      cin >> t;
      g[i] += (!t << j);
    }
  }
  vector<int> state;
  for (int st = 0; st < T; st++) {
    if (!(st & st >> 1)) {
      state.emplace_back(st);
    }
  }
  vector<vector<int>> transition(T);
  for (auto i : state) {
    for (auto j : state) {
      if ((i & j) == 0) {
        transition[i].emplace_back(j);
      }
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(T));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (auto st : state) {
      for (auto tr : transition[st]) {
        if ((st & g[i]) == 0) {
          dp[i][st] = (dp[i][st] + dp[i - 1][tr]) % mod;
        }
      }
    }
  }
  int ans = 0;
  for (auto st : state) {
    ans = (ans + dp[n][st]) % mod;
  }
  cout << ans << '\n';
  return 0;
}
