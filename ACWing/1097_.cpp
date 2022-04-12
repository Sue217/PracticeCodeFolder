/**
 *    author: subobo
 *    created: 11.04.2022 23:11:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  vector used(n, vector<bool>(m));
  array<int, 8> dx{-1, -1, -1, 0, 1, 1, 1, 0}, dy{-1, 0, 1, 1, 1, 0, -1, -1};
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector<pair<int, int>> que;
      if (!used[i][j] && g[i][j] == 'W') {
        ans += 1;
        que.emplace_back(i, j);
        used[i][j] = true;
        for (int b = 0; b < (int) que.size(); b++) {
          int x = que[b].first;
          int y = que[b].second;
          for (int d = 0; d < 8; d++) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (0 <= xx && xx < n && 0 <= yy && yy < m && !used[xx][yy] && g[xx][yy] == 'W') {
              que.emplace_back(xx, yy);
              used[xx][yy] = true;
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
