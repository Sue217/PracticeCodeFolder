/**
 *    author: subobo
 *    created: 13.02.2022 10:41:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  array<int, 4> dx{0, 1, 0, -1}, dy{1, 0, -1, 0};
  auto Bfs = [&](int x, int y) {
    int area = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      area += 1;
      for (int i = 0; i < 4; i++) {
        int xx = t.first + dx[i], yy = t.second + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m
            && !vis[xx][yy] && !(g[xx][yy] >> i & 1)) {
          q.push(make_pair(xx, yy));
          vis[xx][yy] = true;
        }
      }
    }
    return area;
  };
  int room = 0, area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        area = max(area, Bfs(i, j));
        room += 1;
      }
    }
  }
  cout << room << '\n';
  cout << area << '\n';
  return 0;
}