/**
 *    author: subobo
 *    created: 17.06.2022 09:34:02
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
T dijkstra(const vector<vector<pair<int, int>>>& g, int from, int to) {
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
  debug(dist);
  return dist[to];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, c, ts, te;
  cin >> t >> c >> ts >> te;
  --ts;
  --te;
  vector<vector<pair<int, int>>> g(t);
  for (int i = 0; i < c; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  cout << dijkstra<int>(g, ts, te) << '\n';
  return 0;
}