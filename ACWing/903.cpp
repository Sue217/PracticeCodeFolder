/**
 *    author: subobo
 *    created: 17.06.2022 23:21:10
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
T dijkstra(const vector<vector<int>>& price, const vector<int>& level, int from, int to, int l, int r) {
  auto inf = (int) 1e6;
  int n = (int) level.size();
  assert(0 <= from && from < n && 0 <= to && to < n);
  vector<int> dist(n, inf);
  vector<int> vis(n);
  dist[from] = 0;
  for (int i = 1; i < n; i++) {
    int t = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && (t == -1 || dist[j] < dist[t])) {
        t = j;
      }
    }
    vis[t] = true;
    for (int j = 1; j < n; j++) {
      if (l <= level[j] && level[j] <= r) {
        dist[j] = min(dist[j], dist[t] + price[t][j]);
      }
    }
  }
  debug(dist);
  return dist[1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  constexpr int inf = (int) 1e6;
  vector<int> level(n + 1);
  vector<vector<int>> price(n + 1, vector<int>(n + 1, inf));
  for (int i = 1; i <= n; i++) price[i][i] = 0;
  for (int i = 1; i <= n; i++) {
    int p, x;
    cin >> p >> level[i] >> x;
    price[0][i] = min(price[0][i], p);
    for (int j = 0; j < x; j++) {
      int t, v;
      cin >> t >> v;
      price[t][i] = min(price[t][i], v);
    }
  }
  int ans = inf;
  for (int i = level[1] - m; i <= level[1]; i++) {
    ans = min(ans, dijkstra<int>(price, level, 0, n, i, i + m));
  }
  cout << ans << '\n';
  return 0;
}