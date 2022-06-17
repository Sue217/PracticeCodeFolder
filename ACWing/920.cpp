/**
 *    author: subobo
 *    created: 17.06.2022 22:04:25
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
  int m, n;
  cin >> m >> n;
  cin.get();
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    string s;
    getline(cin, s);
    stringstream sin(s);
    vector<int> a;
    int x;
    while (sin >> x) a.push_back(x);
    for (int j = 0; j < (int) a.size(); j++) {
      for (int k = j + 1; k < (int) a.size(); k++) {
        g[a[j] - 1].emplace_back(a[k] - 1, 1);
      }
    }
  }
  int ans = dijkstra(g, 0, n - 1);
  if (ans == numeric_limits<int>::max()) {
    cout << "NO" << '\n';
  } else {
    cout << ans - 1 << '\n';
  }
  cerr << "time: " << clock() / 1000 << " ms" << '\n';
  return 0;
}