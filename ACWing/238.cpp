/**
 *    author: subobo
 *    created: 27.01.2022 15:00:00
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p, sz, d;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    sz.assign(n, 1);
    d.resize(n);
  }

  inline int get(int x) {
    if (x != p[x]) {
      int root = get(p[x]);
      d[x] += d[p[x]];
      p[x] = root;
    }
    return p[x];
  }

  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    p[x] = y;
    d[x] = sz[y];
    sz[y] += sz[x];
  }

  inline int dist(int x, int y) {
    int px = get(x);
    int py = get(y);
    if (px == py) {
      return max(0, abs(d[x] - d[y]) - 1);
    }
    return -1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  dsu d(30003);
  for (int i = 0; i < n; i++) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'M') {
      d.unite(x, y);
    } else {
      cout << d.dist(x, y) << '\n';
    }
  }
  return 0;
}