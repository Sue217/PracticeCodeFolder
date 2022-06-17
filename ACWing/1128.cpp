/**
 *    author: subobo
 *    created: 17.06.2022 11:59:56
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
vector<T> dijkstra(const vector<vector<pair<int, int>>>& g, int from, int to) {
  int n = (int) g.size();
  auto inf = numeric_limits<T>::max();
  assert(0 <= from && from < n && 0 <= to && to < n);
  vector<T> dist(n, inf);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> s;
  dist[from] = 0;
  s.emplace(dist[from], from);
  while (!s.empty()) {
    T expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (auto& e : g[i]) {
      int to = e.first;
      int cost = e.second;
      if (dist[i] + cost < dist[to]) {
        dist[to] = dist[i] + cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  auto dist = dijkstra<int>(g, 0, n - 1);
  debug(dist);
  int ans = *max_element(dist.begin(), dist.end());
  cout << (ans == numeric_limits<int>::max() ? -1 : ans) << '\n';
  return 0;
}