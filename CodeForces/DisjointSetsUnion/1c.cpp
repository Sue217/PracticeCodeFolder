/**
 *    author: subobo
 *    created: 22.03.2022 21:59:29
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
  vector<int> p, g, eg;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    g.resize(n);
    eg.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    while (x != p[x]) {
      x = p[x];
    }
    return x;
  }

  inline bool unite(int x, int y) {
    int px = x;
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      eg[px] = g[y];
      return true;
    }
    return false;
  }

  inline void add(int x, int y) {
    x = get(x);
    cerr << x << '\n';
    g[x] += y;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  dsu d(n);
  while (q--) {
    string op;
    cin >> op;
    if (op == "add") {
      int x, y;
      cin >> x >> y;
      --x;
      d.add(x, y);
    }
    if (op == "join") {
      int x, y;
      cin >> x >> y;
      --x; --y;
      d.unite(x, y);
    }
    if (op == "get") {
      int x;
      cin >> x;
      --x;
      cout << d.g[d.get(x)] - d.eg[x] << '\n';
      // cerr << x << " " << d.eg[x] << '\n';
    }
  }
  return 0;
}