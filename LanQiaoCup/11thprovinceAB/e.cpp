/**
 *    author: subobo
 *    created: 31.03.2022 16:57:31
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
  vector<int> p, g, eg, sz;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    g.resize(n);
    eg.resize(n);
    sz.resize(n);
    iota(p.begin(), p.end(), 0);
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
    eg[x] = g[y];
    sz[y] += sz[x];
    return true;
  }

  inline void add(int x, int t) {
    x = get(x);
    g[x] += t;
  }

  inline int goal(int x) {
    return x == p[x] ? g[x] : (g[x] - eg[x] + goal(p[x]));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  dsu d(n);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      d.unite(x, y);
    }
    if (op == 2) {
      int x, t;
      cin >> x >> t;
      --x;
      d.add(x, t);
    }
  }
  for (int x = 0; x < n; x++) {
    cout << d.goal(x) << " \n"[x == n - 1];
  }
  return 0;
}