/**
 *    author: subobo
 *    created: 06.02.2022 11:08:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
    int n;
  cin >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1));
  int x, y, z;
  while (cin >> x >> y >> z, x || y || z) {
    g[x][y] = z;
  }
  vector<vector<vector<int>>> f (
    n * 2 + 1, vector<vector<int>> (
      n + 1, vector<int> (
        n + 1, 0)));
  for (int s = 2; s <= n * 2; s++) {
    for (int x1 = 1; x1 <= n; x1++) {
      for (int x2 = 1; x2 <= n; x2++) {
        int y1 = s - x1, y2 = s - x2;
        if (y1 >= 1 && y1 <= n && y2 >= 1 && y2 <= n) {
          int v = g[x1][y1];
          if (x1 != x2) {
            v += g[x2][y2];
          }
          f[s][x1][x2] = max(f[s][x1][x2], max({f[s - 1][x1][x2], f[s - 1][x1 - 1][x2], f[s - 1][x1][x2 - 1], f[s - 1][x1 - 1][x2 - 1]}) + v);
        }
      }
    }
  }
  cout << f[n << 1][n][n] << '\n';
  return 0;
}