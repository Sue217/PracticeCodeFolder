/**
 *    author: subobo
 *    created: 27.01.2022 21:19:29
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p, d;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
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

  inline bool is_united(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return true;
    }
    return false;
  }

  inline void unite(int x, int y, int t) {
    int px = get(x);
    int py = get(y);
    if (px != py) {
      p[px] = py;
      d[px] = d[y] - d[x] + t;
      // (d[x] + d[px] + ?) % 3 = d[y] % 3
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);
  int fakes = 0;
  for (int i = 0; i < m; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (x > n || y > n) {
      fakes += 1;
      continue;
    }
    if (op == 1) {
      if (d.is_united(x, y)) {
        if ((d.d[x] - d.d[y]) % 3 != 0) {
          fakes += 1;
        }
      } else {
        d.unite(x, y, 0);
      }
    } else {
      if (x == y) {
        fakes += 1;
        continue;
      }
      if (d.is_united(x, y)) {
        if ((d.d[x] - 1 - d.d[y]) % 3 != 0) {
          fakes += 1;
        }
      } else {
        d.unite(x, y, 1);
      }
    }
  }
  cout << fakes << '\n';
  return 0;
}