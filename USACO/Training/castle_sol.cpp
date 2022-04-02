/*
  ID: sujingb1
  TASK: castle
  LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;

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
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
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
  
  inline int size(int x) {
    x = get(x);
    return sz[x];
  }
};

int main() {
  ifstream fin ("castle.in");
  ofstream fout ("castle.out");
  int n, m;
  fin >> m >> n;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      fin >> g[i][j];
    }
  }
  dsu d(n * m);
  int rooms = n * m;
  int mx = 1;
  array<int, 4> dx{0, -1, 0, 1}, dy{-1, 0, 1, 0}, wall{1, 2, 4, 8}; // WNES
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      int c = x * m + y;
      for (int dd = 0; dd < 4; dd++) {
        if ((g[x][y] >> dd & 1) == 0) {
          int xx = x + dx[dd];
          int yy = y + dy[dd];
          if (0 <= xx && xx < n && 0 <= yy && yy < m) {
            int cc = xx * m + yy;
            if (d.unite(c, cc)) {
              rooms -= 1;
              mx = max(mx, d.size(cc));
            }
          }
        }
      }
    }
  }
  fout << rooms << '\n';
  fout << mx << '\n';
  int wa = 0, wx = 0, wy = 0;
  for (int y = 0; y < m; y++) {
    for (int x = n - 1; x >= 0; x--) {
      int c = x * m + y;
      for (int dd = 0; dd < 4; dd++) {
        if ((g[x][y] >> dd & 1) != 0) {
          int xx = x + dx[dd];
          int yy = y + dy[dd];
          if (0 <= xx && xx < n && 0 <= yy && yy < m) {
            int cc = xx * m + yy;
            if (!d.united(c, cc) && mx < d.size(c) + d.size(cc)) {
              mx = d.size(c) + d.size(cc);
              wa = dd;
              wx = x + 1;
              wy = y + 1;
            }
          }
        }
      }
    }
  }
  char w;
  switch (wa) {
    case 0: w = 'W'; break;
    case 1: w = 'N'; break;
    case 2: w = 'E'; break;
    case 3: w = 'S'; break;
  }
  fout << mx << '\n';
  fout << wx << " " << wy << " " << w << '\n';
  return 0;
}