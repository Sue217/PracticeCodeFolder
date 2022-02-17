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
    if ((r + c) % 2 == 1) {
      puts("NO SOLUTION");
      continue;
    }
    vector<string> g(r);
    for (string& in : g) {
      cin >> in;
    }
    deque<pair<int, int>> dq;
    vector<vector<int>> dist(r, vector<int>(c, -1));
    array<int, 4> dx{-1, -1, 1, 1}, dy{-1, 1, -1, 1};
    dq.push_back(make_pair(0, 0));
    dist[0][0] = 0;
    while (!dq.empty()) {
      auto t = dq.front();
      dq.pop_front();
      int x = t.first, y = t.second;
      int d = dist[x][y];
      cerr << x << ", " << y << '\n';
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < r && yy >= 0 && yy < c && dist[xx][yy] == -1) {
          if (i == 0 && i == 3) {
            if (g[x][y] == '/') {
              dist[xx][yy] = d + 1;
              dq.push_back(make_pair(xx, yy));
            } else {
              dist[xx][yy] = d;
              dq.push_front(make_pair(xx, yy));
            }
          } else {
            if (g[x][y] == '/') {
              dist[xx][yy] = d;
              dq.push_front(make_pair(xx, yy));
            } else {
              dist[xx][yy] = d + 1;
              dq.push_back(make_pair(xx, yy));
            }
          }
        }
      }
    }
    cout << dist[r - 1][c - 1] << '\n';
  }
  return 0;
}