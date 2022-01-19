/**
 *    author: subobo
 *    created: 18.01.2022 23:21:33
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
  int u;
  int d;
  int w;
  friend bool operator< (const node& a, const node& b) {
    if (a.d == b.d) {
      return a.w > b.w;
    }
    return a.d > b.d;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, st, ed;
  cin >> n >> m >> st >> ed;
  vector<int> h(m * 2 + 1, -1), e(m * 2 + 1), ne(m * 2 + 1), dd(m * 2 + 1), cc(m * 2 + 1);
  int idx = 0;
  auto Add = [&](int a, int b, int c, int d) {
    e[idx] = b;
    dd[idx] = c;
    cc[idx] = d;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int i = 0; i < m; i++) {
    int u, v, d, w;
    cin >> u >> v >> d >> w;
    Add(u, v, d, w);
    Add(v, u, d, w);
  }
  vector<bool> vis(n);
  constexpr int inf = (int)2e9;
  vector<int> dist(n, inf), cost(n, inf);
  dist[st] = cost[st] = 0;
  priority_queue<node> q;
  q.push({st, 0, 0});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i], d = dd[i], w = cc[i];
      if (dist[v] >= dist[u] + d) {
        if (dist[v] == dist[u] + d) {
          cost[v] = min(cost[v], cost[u] + w);
        } else {
          dist[v] = dist[u] + d;
          cost[v] = cost[u] + w;
          q.push({v, dist[v], cost[v]});
        }
      }
    }
  }
  cout << dist[ed] << " " << cost[ed] << '\n';
  return 0;
}