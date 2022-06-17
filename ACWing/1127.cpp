/**
 *    author: subobo
 *    created: 17.06.2022 12:43:18
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
  int n, p, c;
  cin >> n >> p >> c;
  vector<int> cows(p);
  for (int i = 0; i < n; i++) {
    int pp;
    cin >> pp;
    --pp;
    cows[pp] += 1;
  }
  vector<vector<pair<int, int>>> g(p);
  for (int i = 0; i < c; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  int ans = (int) 2e9;
  for (int i = 0; i < p; i++) {
    int sum = 0;
    auto dist = dijkstra<int>(g, i, p - 1);
    for (int j = 0; j < p; j++) {
      if (i == j) continue;
      sum += dist[j] * cows[j];
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}