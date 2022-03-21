/**
 *    author: subobo
 *    created: 29.01.2022 19:04:32
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

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
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
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (!d.unite(x, y)) {
      cnt += 1;
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d.unite(i, j)) {
        puts("NO");
        return 0;
      }
    }
  }
  if (cnt == 1) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}