/**
 *    author: subobo
 *    created: 20.03.2022 18:12:54
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 0; qq < tt; qq++) {
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    // assert(g[xa][ya] == '.' && g[xb][yb] == '.');
    if (g[xa][ya] == '#' || g[xb][yb] == '#') {
      cout << "NO";
      if (qq != tt - 1) {
        cout << '\n';
      }
      continue;
    }
    array<int, 4> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
    vector<vector<int>> vis(n, vector<int>(n));
    queue<pair<int, int>> que;
    que.emplace(xa, ya);
    vis[xa][ya] = true;
    bool reached = false;
    while (!que.empty()) {
      auto t = que.front();
      que.pop();
      int x = t.first, y = t.second;
      if (x == xb && y == yb) {
        reached = true;
        break;
      }
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < n && g[xx][yy] == '.' && !vis[xx][yy]) {
          que.emplace(xx, yy);
          vis[xx][yy] = true;
        }
      }
    }
    if (reached) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    if (qq != tt - 1) {
      cout << '\n';
    }
  }
  return 0;
}