/**
 *    author: subobo
 *    created: 20.02.2022 15:12:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(m + 1, -1), e(m + 1), ne(m + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<pair<int, int>> p;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    p.emplace_back(u, v);
  }
  sort(p.begin(), p.end(), [](const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  for (auto it : p) {
    // cerr << it.first << " " << it.second << '\n';
    Add(it.first, it.second);
  }
  vector<bool> vis(n + 1, false);
  vis[1] = true;
  function<void(int)> Dfs = [&](int u) {
    cout << u << " ";
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      if (!vis[son]) {
        vis[son] = true;
        Dfs(son);
      }
    }
  };
  Dfs(1);
  cout << '\n';
  fill(vis.begin(), vis.end(), false);
  auto Bfs = [&](int st) {
    queue<int> q;
    q.push(st);
    vis[st] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      cout << u << " ";
      for (int id = h[u]; id != -1; id = ne[id]) {
        int son = e[id];
        if (!vis[son]) {
          q.push(son);
          vis[son] = true;
        }
      }
    }
  };
  Bfs(1);
  cout << '\n';
  return 0;
}