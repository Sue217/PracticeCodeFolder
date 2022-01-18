/**
 *    author: subobo
 *    created: 18.01.2022 21:21:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, st, ed;
  cin >> n >> m >> st >> ed;
  vector<vector<int>> D(n, vector<int>(n, 0)), C(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int u, v, d, w;
    cin >> u >> v >> d >> w;
    D[u][v] = D[v][u] = d;
    C[u][v] = C[v][u] = w;
  }
  constexpr int inf = (int)2e9;
  vector<vector<int>> dist(n, vector<int>(n, inf)), cost(n, vector<int>(n, inf));
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][j] == D[i][k] + D[k][j]) {
          cost[i][j] = min(cost[i][j], C[i][k] + C[k][j]);
        } else
        if (dist[i][j] > D[i][k] + D[k][j]) {
          dist[i][j] = D[i][k] + D[k][j];
          cost[i][j] = C[i][k] + C[k][j];
        }
      }
    }
  }
  cout << dist[st][ed] << " " << cost[st][ed] << '\n';
  return 0;
}