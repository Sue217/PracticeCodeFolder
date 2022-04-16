#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector g(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  bitset<1000000> used;
  array<int, 8> dx{-1, -1, -1, 0, 1, 1, 1, 0};
  array<int, 8> dy{-1, 0, 1, 1, 1, 0, -1, -1};
  int p = 0, v = 0;
  bool neq = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!used[i * n + j]) {
        vector<pair<int, int>> que;
        que.emplace_back(i, j);
        used[i * n + j] = 1;
        bool higher = false;
        bool lower = false;
        for (int b = 0; b < (int) que.size(); b++) {
          int x = que[b].first;
          int y = que[b].second;
          for (int d = 0; d < 8; d++) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if (0 <= xx && xx < n && 0 <= yy && yy < n) {
              if (g[xx][yy] == g[x][y] && !used[xx * n + yy]) {
                que.emplace_back(xx, yy);
                used[xx * n + yy] = 1;
              }
              if (g[xx][yy] > g[x][y]) higher = true;
              if (g[xx][yy] < g[x][y]) lower = true;
            }
          }
        }
        if (higher && lower) continue;
        if (higher || lower) neq = true;
        if (higher) v += 1;
        if (lower) p += 1;
      }
    }
  }
  if (!neq) {
    cout << 1 << " " << 1 << '\n';
  } else {
    cout << p << " " << v << '\n';
  }
  return 0;
}