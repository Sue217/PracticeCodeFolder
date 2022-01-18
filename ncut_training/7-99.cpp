/**
 *    author: subobo
 *    created: 18.01.2022 14:08:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u][v] = g[v][u] = w;
  }
  int tt;
  cin >> tt;
  int nice = tt;
  int index = 0;
  long long ans = (int)2e9;
  for (int id = 1; id <= tt; id++) {
    int x;
    cin >> x;
    vector<int> path;
    set<int> pt;
    for (int i = 0; i < x; i++) {
      int p;
      cin >> p;
      path.emplace_back(p);
      pt.insert(p);
    }
    if ((int)pt.size() < x or (int)path.size() < n or g[0][path.front()] == -1 or g[path.back()][0] == -1) {
      nice -= 1;
      continue;
    }
    long long cnt = g[0][path.front()] + g[path.back()][0];
    bool ok = true;
    for (int i = 0; i < (int)path.size() - 1; i++) {
      if (g[path[i]][path[i + 1]] == -1) {
        nice -= 1;
        ok = false;
        break;
      }
      cnt += g[path[i]][path[i + 1]];
    }
    if (ok and ans > cnt) {
      ans = cnt;
      index = id;
    }
  }
  cout << nice << '\n';
  cout << index << " " << ans << '\n';
  return 0;
}