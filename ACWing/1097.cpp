/**
 *    author: subobo
 *    created: 13.02.2022 09:14:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  array<int, 8> dx{-1, -1, -1, 0, 0, 1, 1, 1}, dy{-1, 0, 1, -1, 1, -1, 0, 1};
  auto Bfs = [&](int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      for (int i = 0; i < 8; i++) {
        int xx = t.first + dx[i], yy = t.second + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == 'W' && !vis[xx][yy]) {
          vis[xx][yy] = true;
          q.push(make_pair(xx, yy));
        }
      }
    }
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && g[i][j] == 'W') {
        ans += 1;
        Bfs(i, j);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}