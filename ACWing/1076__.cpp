/**
 *    author: subobo
 *    created: 13.02.2022 20:53:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<char>> g(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  array<int, 4> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
  vector<vector<pair<int, int>>> from(n, vector<pair<int, int>>(n, make_pair(-1, -1)));
  auto Bfs = [&](int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    from[x][y] = make_pair(-2, -2);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      int x = t.first, y = t.second;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && from[xx][yy].first == -1 && g[xx][yy] == '0') {
          q.push(make_pair(xx, yy));
          from[xx][yy] = make_pair(x, y);
        }
      }
    }
  };
  Bfs(0, 0);
  auto pre = from[n - 1][n - 1];
  vector<pair<int, int>> ans(1, make_pair(n - 1, n - 1));
  while (pre.first != -2 && pre.second != -2) {
    ans.emplace_back(pre.first, pre.second);
    pre = from[pre.first][pre.second];
  }
  for (auto it = ans.rbegin(); it != ans.rend(); it++) {
    cout << (*it).first << " " << (*it).second << '\n';
  }
  return 0;
}