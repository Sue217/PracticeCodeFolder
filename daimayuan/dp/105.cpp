/**
 *    author: subobo
 *    created: 21.02.2022 10:52:04
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
  depth[1] = 1;
  for (int id = 2; id <= n; id++) {
    cin >> fa[id];
    Add(fa[id], id);
    depth[id] = depth[fa[id]] + 1;
  }
  vector<vector<pair<int, int>>> path(n + 1);
  vector<int> w(n, 0);
  for (int i = 0; i < m; i++) {
    int u, v, a;
    cin >> u >> v >> a;
    path[v].emplace_back(u, a);
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
  vector<long long> suf_a(n + 2, 0), suf_b(n + 2, 0);
  constexpr static long long inf = (long long) 1e18;
  function<void(int)> Dfs = [&](int u) {
    for (int d = 1; d <= depth[u]; d++) {
      dp[u][d] = inf; // dp[u][depth[u] + 1] = 0, cover to u
    }
    for (auto p : path[u]) {
      dp[u][depth[p.first]] = min(dp[u][depth[p.first]], (long long) p.second);
    }
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      Dfs(son);
      int len = depth[son];
      suf_a[len + 1] = inf;
      suf_b[len + 1] = inf;
      for (int i = len; i >= 1; i--) {
        suf_a[i] = min(suf_a[i + 1], dp[u][i]);
        suf_b[i] = min(suf_b[i + 1], dp[son][i]);
      }
      for (int i = 1; i <= len; i++) {
        dp[u][i] = min(dp[u][i] + suf_b[i], dp[son][i] + suf_a[i]);
      }
      /*
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= depth[son]; j++) {
          Cap[min(i, j)] = min(Cap[min(i, j)], dp[u][i] + dp[son][j]);
        }
      } */
    }
  };
  Dfs(1);
  if (dp[1][1] >= inf) {
    cout << -1 << '\n';
  } else {
    cout << dp[1][1] << '\n';
  }
  return 0;
}