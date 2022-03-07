/**
 *    author: Jingbo Su
 *    created: 07.03.2022
**/
#include <bits/stdc++.h>
#include "./graph.h"

using namespace std;

template <typename T>
vector<T> dijkstra(const graph<T>& g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> s;
  dist[start] = 0;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    T expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int id : g.g[i]) {
      auto& e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
  // returns numeric_limits<T>::max() if there is no path
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  digraph<int> g(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g.add(x, y, z);
  }
  int dist = dijkstra(g, 1)[n];
  cout << (dist == numeric_limits<int>::max() ? -1 : dist) << '\n';
  return 0;
}