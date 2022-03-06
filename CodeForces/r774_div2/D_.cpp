/**
 *    author: subobo
 *    created: 06.03.2022 00:30:22
**/
#include <bits/stdc++.h>

using namespace std;

inline bool comp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n == 2) {
    cout << 2 << " " << 2 << '\n';
    cout << 1 << " " << 1 << '\n';
    return 0;
  }
  vector dp(n + 1, vector<pair<int, int>>(2));
  function<void(int, int)> dfs_1 = [&](int v, int pv) {
    dp[v][0] = make_pair(0, 1);
    dp[v][1] = make_pair(1, (int) g[v].size());
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      dfs_1(u, v);
      dp[v][1].first += dp[u][0].first;
      dp[v][1].second += dp[u][0].second;
      if (comp(dp[u][0], dp[u][1])) {
        dp[v][0].first += dp[u][0].first;
        dp[v][0].second += dp[u][0].second;
      } else {
        dp[v][0].first += dp[u][1].first;
        dp[v][0].second += dp[u][1].second;
      }
    }
  };
  dfs_1(1, 0);
  vector<int> ans(n + 1);
  function<void(int, int, int)> dfs_2 = [&](int v, int pv, int get) {
    ans[v] = get;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      if (get == 1) {
        dfs_2(u, v, 0);
      } else {
        if (comp(dp[u][0], dp[u][1])) {
          dfs_2(u, v, 0);
        } else {
          dfs_2(u, v, 1);
        }
      }
    }
  };
  if (comp(dp[1][0], dp[1][1])) {
    cout << dp[1][0].first << " " << dp[1][0].second << '\n';
    dfs_2(1, 0, 0);
  } else {
    cout << dp[1][1].first << " " << dp[1][1].second << '\n';
    dfs_2(1, 0, 1);
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] != 0) {
      cout << g[i].size() << " \n"[i == n];
    } else {
      cout << 1 << " \n"[i == n];
    }
  }
  return 0;
}