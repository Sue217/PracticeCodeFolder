/**
 *    author: subobo
 *    created: 15.02.2022 20:47:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m));
  vector<vector<int>> dist(n, vector<int>(m, -1));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] == '1') {
        q.push(make_pair(i, j));
        dist[i][j] = 0;
      }
    }
  }
  array<int, 4> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    int x = t.first, y = t.second;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && dist[xx][yy] == -1) {
        dist[xx][yy] = dist[x][y] + 1;
        q.push(make_pair(xx, yy));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dist[i][j] << " \n"[j == m - 1];
    }
  }
  return 0;
}