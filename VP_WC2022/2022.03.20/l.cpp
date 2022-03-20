/**
 *    author: subobo
 *    created: 20.03.2022 20:48:44
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, e;
  const int inf = (int) 1e9;
  while (cin >> n >> m >> e) {
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (int i = 0; i < e; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u][v] = g[v][u] = min(g[u][v], w);
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    int d1 = inf, d2 = inf;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] < d1) {
          d2 = d1;
          d1 = g[i][j];
        } else
        if (g[i][j] < d2) {
          d2 = g[i][j];
        }
      }
    }
    int ans = d1 + d2;
    if (ans == inf + inf) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}