/**
 *    author: subobo
 *    created: 17.06.2022 13:16:51
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
T dijkstra(const vector<vector<pair<int, T>>>& g, int from, int to) {
  int n = (int) g.size();
  auto inf = numeric_limits<T>::max();
  const double eps = 1e-31;
  assert(0 <= from && from < n && 0 <= to && to < n);
  vector<T> dist(n);
  priority_queue<pair<T, int>, vector<pair<T, int>>, less<pair<T, int>>> s;
  dist[from] = 1;
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
      T cost = e.second;
      if (dist[i] * cost > dist[to]) {
        dist[to] = dist[i] * cost;
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
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, double>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].emplace_back(v, (double) (100 - w) / 100.0);
    g[v].emplace_back(u, (double) (100 - w) / 100.0);
  }
  int a, b;
  cin >> a >> b;
  --a;
  --b;
  double rate = dijkstra<double>(g, a, b);
  cout << fixed << setprecision(8) << 100.0 / rate << '\n';
  return 0;
}