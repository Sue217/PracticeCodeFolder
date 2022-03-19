/**
 *    author: subobo
 *    created: 19.03.2022 21:13:12
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
  vector<int> p; // d, sz
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    // d.resize(n);
    // sz.assign(n, 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
    // if (x != p[x]) {
    //   int root = get(p[x]);
    //   d[x] += d[p[x]];
    //   p[x] = root;
    // }
    // return p[x];
  }

  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
    }
  }

  inline bool united(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      return false;
    }
    return true;
  }

  // dist = abs(d[x] - d[y])...
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  dsu d(n + 1);
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      d.unite(u, v);
    }
    if (t == 1) {
      cout << d.united(u, v) << '\n';
    }
  }
  return 0;
}