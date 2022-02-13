/**
 *    author: subobo
 *    created: 13.02.2022 17:59:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(n));
  array<int, 8> dx{-1, -1, -1, 0, 0, 1, 1, 1};
  array<int, 8> dy{-1, 0, 1, -1, 1, -1, 0, 1};
  auto Bfs = [&](int x, int y) {
    bool higher = true, lower = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      for (int i = 0; i < 8; i++) {
        int xx = t.first + dx[i], yy = t.second + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
          if (g[xx][yy] == g[x][y]) {
            if (!vis[xx][yy]) {
              q.push(make_pair(xx, yy));
              vis[xx][yy] = true;
            }
          } else {
            if (g[xx][yy] > g[x][y]) {
              higher = false;
            } else {
              lower = false;
            }
          }
        }
      }
    }
    if (higher && lower) {
      return 0;
    }
    if (higher) {
      return 1;
    }
    if (lower) {
      return 2;
    }
    return 3;
  };
  int peak = 0, valley = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!vis[i][j]) {
        int v = Bfs(i, j);
        if (v == 0) {
          cout << 1 << " " << 1 << '\n';
          return 0;
        }
        if (v == 1) {
          peak += 1;
        } else 
        if (v == 2) {
          valley += 1;
        }
      }
    }
  }
  cout << peak << " " << valley << '\n';
  return 0;
}