/**
 *    author: subobo
 *    created: 22.01.2022 08:51:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  const int T = 1 << m;
  vector<int> g(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      int gi;
      if (c == 'H') {
        g[i] += 1 << j;
      }
    }
  }
  auto count = [&](int cnt) {
    int v = 0;
    for (int i = 0; i < m; i++) {
      v += cnt >> i & 1;
    }
    return v;
  };
  vector<int> state;
  unordered_map<int, int> cnt;
  for (int st = 0; st < T; st++) {
    if (!(st & st >> 1 || st & st >> 2)) {
      state.emplace_back(st);
      cnt[st] = count(st);
    }
  }
  vector<vector<int>> transition(T);
  for (int i : state) {
    for (int j : state) {
      if ((i & j) == 0) {
        transition[i].emplace_back(j);
      }
    }
  }
  vector<vector<vector<int>>> dp(2, vector<vector<int>>(T, vector<int>(T, 0)));
  for (int id = 1; id <= n; id++) {
    for (int st : state) {
      if ((g[id] & st) == 0) {
        for (int tr1 : transition[st]) {
          for (int tr2 : transition[tr1]) {
            if ((st & tr2) == 0) {
              dp[id & 1][st][tr1] = max(dp[id & 1][st][tr1], dp[(id - 1) & 1][tr1][tr2] + cnt[st]);
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int st : state) {
    for (int tr : transition[st]) {
      ans = max(ans, dp[n & 1][st][tr]);
    }
  }
  cout << ans << '\n';
  return 0;
}
