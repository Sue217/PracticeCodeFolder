/**
 *    author: subobo
 *    created: 16.02.2022 16:10:34
**/
#include <bits/stdc++.h>

using namespace std;

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

  inline bool is_united(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return true;
    }
    return false;
  }

  // dist = abs(d[x] - d[y])...
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
    cin >> ops >> u >> v;
    if (ops == "union") {
      d.unite(u, v);
    } else {
      if (d.is_united(u, v)) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
  }
  return 0;
}