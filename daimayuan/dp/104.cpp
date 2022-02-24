/**
 *    author: subobo
 *    created: 18.02.2022 21:59:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(n + 1, -1), e(n + 1), ne(n + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<int> fa(n + 1, -1), depth(n + 1, 0);
  for (int id = 2; id <= n; id++) {
    cin >> fa[id];
    Add(fa[id], id);
    depth[id] = depth[fa[id]] + 1;
  }
  vector<vector<tuple<int, int, int>>> path(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    int x = u, y = v;
    while (x != y) {
      if (depth[x] > depth[y]) {
        x = fa[x];
      } else {
        y = fa[y];
      }
    }
    path[x].emplace_back(u, v, w);
  }
  vector<long long> dp(n + 1, 0), sum(n + 1, 0);
  function<void(int)> Dfs = [&](int u) {
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      Dfs(son);
      sum[u] += dp[son];
    }
    dp[u] = sum[u];
    for (auto p : path[u]) {
      // long long delta = 0;
      long long delta = sum[u];
      int node = get<0>(p);
      while (node != u) {
        delta += sum[node] - dp[node];
        node = fa[node];
      }
      node = get<1>(p);
      while (node != u) {
        delta += sum[node] - dp[node];
        node = fa[node];
      }
      // cerr << delta << '\n';
      delta += get<2>(p);
      dp[u] = max(dp[u], delta);
    }
  };
  Dfs(1);
  cout << dp[1] << '\n';
  return 0;
}