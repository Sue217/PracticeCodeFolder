/**
 *    author: subobo
 *    created: 17.02.2022 19:37:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> g(r + 2, vector<char>(c + 2));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> g[i][j];
      }
    }
    deque<pair<int, int>> dq;
    constexpr int inf = (int) 2e9;
    vector<vector<int>> dist(r + 2, vector<int>(c + 2, inf));
    array<int, 4> dx{-1, -1, 1, 1}, dy{-1, 1, -1, 1};
    array<int, 4> ix{-1, -1, 0, 0}, iy{-1, 0, -1, 0};
    string s = "\\//\\";
    dq.push_back(make_pair(0, 0));
    dist[0][0] = 0;
    while (!dq.empty()) {
      auto t = dq.front();
      dq.pop_front();
      int x = t.first, y = t.second;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx <= r && yy >= 0 && yy <= c) {
          int px = x + ix[i], py = y + iy[i];
          if (px >= 0 && px < r && py >= 0 && py < c) {
            auto is_equal = g[px][py] != s[i];
            if (dist[xx][yy] > dist[x][y] + is_equal) {
              dist[xx][yy] = dist[x][y] + is_equal;
              if (is_equal) {
                dq.push_back(make_pair(xx, yy));
              } else {
                dq.push_front(make_pair(xx, yy));
              }
            }
          }
        }
      }
    }
    if (dist[r][c] == inf) {
      cout << "NO SOLUTION" << '\n';
    } else {
      cout << dist[r][c] << '\n';
    }
  }
  return 0;
}