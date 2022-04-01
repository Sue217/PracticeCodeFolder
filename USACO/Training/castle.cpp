/**
 *    author: subobo
 *    created: 01.04.2022 20:55:36
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p, sz;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.resize(n);
    fill(sz.begin(), sz.end(), 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : get(p[x]));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    // if (sz[x] > sz[y]) {
    //   swap(x, y);
    // }
    p[x] = y;
    sz[y] += sz[x];
    return true;
  }

  inline bool united(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  dsu d(n * m);
  array<int, 4> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
  string wall = "NWSE";
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      for (int dd = 0; dd < 4; dd++) {
        if ((g[x][y] >> dd & 1) == 0) {
          int xx = x + dx[dd];
          int yy = y + dy[dd];
          if (0 <= xx && xx < n && 0 <= yy && yy < m) {
            int c = x * m + y;
            int cc = xx * m + yy;
            d.unite(c, cc);
          }
        }
      }
    }
  }
  int rooms = 0, mx = 1;
  for (int cc = 0; cc < n * m; cc++) {
    if (d.get(cc) == cc) {
      rooms += 1;
      mx = max(mx, d.sz[cc]);
    }
  }
  cout << rooms << '\n';
  cout << mx << '\n';
  int wa = 0, wx = 0, wy = 0;
  // for (int y = m - 1; y >= 0; y--) {
  //   for (int x = 0; x < n; x++) {
  for (int y = 0; y < m; y++) {
    for (int x = n - 1; x >= 0; x--) {
      for (int dd = 0; dd < 4; dd++) {
        if ((g[x][y] >> dd & 1) == 1) {
          int xx = x + dx[dd];
          int yy = y + dy[dd];
          if (0 <= xx && xx < n && 0 <= yy && yy < m) {
            int c = x * m + y;
            int cc = xx * m + y;
            if (!d.united(c, cc)) {
              if (d.sz[c] + d.sz[cc] > mx) {
                mx = d.sz[c] + d.sz[cc];
                wa = wall[dd];
                wx = x + 1;
                wy = y + 1;
              }
            }
          }
        }
      }
    }
  }
  cout << mx << '\n';
  cout << wx << " " << wy << " " << (wa == 4 ? 'E' : 'N') << '\n';
  return 0;
}