/**
 *    author: subobo
 *    created: 20.02.2022 14:09:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  constexpr int inf = (int) 1e9;
  vector<vector<int>> g(n + 1, vector<int>(n + 1, inf));
  vector<int> time(n, 0);
  for (int& in : time) {
    cin >> in;
  }
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    assert(u != v);
    g[u][v] = g[v][u] = min(g[u][v], w);
  }
  int q;
  cin >> q;
  int p = 0;
  for (int i = 0; i < q; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    for (; time[p] <= t && p < n; p++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (g[i][j] > g[i][p] + g[p][j]) {
            g[i][j] = g[j][i] = g[i][p] + g[p][j];
          }
        }
      }
    }
    if (t < time[x] || t < time[y]) {
      cout << -1 << '\n';
    } else {
      if (g[x][y] == inf) {
        cout << -1 << '\n';
      } else {
        cout << g[x][y] << '\n';
      }
    }
  }
  return 0;
}