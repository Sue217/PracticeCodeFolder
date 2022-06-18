#include <bits/stdc++.h>

using namespace std;

template <typename T>
T dijkstra(const vector<vector<pair<int, T>>>& g, int from, int to) {
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
      T cost = e.second;
      if (dist[i] + cost < dist[to]) {
        dist[to] = dist[i] + cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist[to];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].emplace_back(v, w + c[v]);
    g[v].emplace_back(u, w + c[u]);
  }
  cout << dijkstra<int>(g, 0, n - 1) - c[n - 1] << '\n';
  return 0;
}