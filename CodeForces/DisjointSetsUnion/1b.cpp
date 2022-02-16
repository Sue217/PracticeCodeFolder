/**
 *    author: subobo
 *    created: 16.02.2022 16:24:45
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p, sz, mi, ma;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    mi.resize(n);
    iota(mi.begin(), mi.end(), 0);
    ma.resize(n);
    iota(ma.begin(), ma.end(), 0);
    sz.assign(n, 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline void unite(int x, int y) {
    int px = get(x);
    int py = get(y);
    if (px != py) {
      p[px] = py;
      sz[py] += sz[px];
    }
    mi[px] = mi[py] = min({mi[px], mi[py], x, y});
    ma[px] = ma[py] = max({ma[px], ma[py], x, y});
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);
  for (int i = 0; i < m; i++) {
    string ops;
    int u, v;
    cin >> ops >> u;
    if (ops == "union") {
      cin >> v;
      d.unite(u, v);
    } else {
      int root = d.get(u);
      cout << d.mi[root] << " " << d.ma[root] << " " << d.sz[root] << '\n';
    }
  }
  return 0;
}