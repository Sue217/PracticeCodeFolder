#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  assert(n != 0);
  vector g(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
  }
  assert(g[0][0] == 0);
  bitset<1000000> used;
  vector<int> prev(n * n, -1);
  array<int, 4> dx{-1, 0, 1, 0};
  array<int, 4> dy{0, -1, 0, 1};
  vector<pair<int, int>> que(1, make_pair(0, 0));
  used[0] = 1;
  prev[0] = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    int x = que[b].first;
    int y = que[b].second;
    for (int d = 0; d < 4; d++) {
      int xx = x + dx[d];
      int yy = y + dy[d];
      if (0 <= xx && xx < n && 0 <= yy && yy < n && !used[xx * n + yy] && g[xx][yy] == 0) {
        que.emplace_back(xx, yy);
        used[xx * n + yy] = 1;
        prev[xx * n + yy] = x * n + y;
      }
    }
  }
  int id = (n - 1) * n + n - 1;
  vector<pair<int, int>> path;
  while (id != 0) {
    path.emplace_back(id / n, id % n);
    id = prev[id];
  }
  path.emplace_back(0, 0);
  for (auto it = path.rbegin(); it != path.rend(); it++) {
    cout << it->first << " " << it->second << '\n';
  }
  return 0;
}
