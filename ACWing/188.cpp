/**
 *    author: subobo
 *    created: 14.02.2022 12:47:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int c, r;
  cin >> c >> r;
  vector<vector<char>> g(r, vector<char>(c));
  pair<int, int> start, finish;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> g[i][j];
      if (g[i][j] == 'K') {
        start = make_pair(i, j);
      }
      if (g[i][j] == 'H') {
        finish = make_pair(i, j);
      }
    }
  }
  array<int, 8> dx{-2, -2, -1, -1, 2, 2, 1, 1}, dy{-1, 1, -2, 2, -1, 1, -2, 2};
  vector<vector<int>> dist(r, vector<int>(c, -1));
  auto Bfs = [&](pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    int x = start.first, y = start.second;
    dist[x][y] = 0;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int x = t.first, y = t.second;
      for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < r && yy >= 0 && yy < c && dist[xx][yy] == -1 && (g[xx][yy] == '.' || g[xx][yy] == 'H')) {
          dist[xx][yy] = dist[x][y] + 1;
          q.push(make_pair(xx, yy));
        }
      }
    }
  };
  Bfs(start);
  cout << dist[finish.first][finish.second] << '\n';
  return 0;
}