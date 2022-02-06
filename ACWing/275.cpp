/**
 *    author: subobo
 *    created: 06.02.2022 11:44:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<vector<int>>> f (
    n + m + 1, vector<vector<int>> (
      n + 1, vector<int> (
        n + 1, 0)));
  for (int s = 2; s <= n + m; s++) {
    for (int x1 = 1; x1 <= n; x1++) {
      for (int x2 = 1; x2 <= n; x2++) {
        int y1 = s - x1, y2 = s - x2;
        if (y1 >= 1 && y1 <= m && y2 >= 1 && y2 <= m) {
          int v = g[x1][y1];
          if (x1 != x2) {
            v += g[x2][y2];
          }
          f[s][x1][x2] = max(f[s][x1][x2], max({
            f[s - 1][x1][x2], f[s - 1][x1 - 1][x2], f[s - 1][x1][x2 - 1], f[s - 1][x1 - 1][x2 - 1]}) + v);
        }
      }
    }
  }
  cout << f[n + m][n][n] << '\n';
  return 0;
}