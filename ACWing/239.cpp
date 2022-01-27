/**
 *    author: subobo
 *    created: 27.01.2022 18:18:03
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
      d[x] ^= d[p[x]];
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
      d[px] = d[x] ^ d[y] ^ t;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<int, int> disc;
  int index = 0;
  auto Disc = [&](int x) {
    if (disc.count(x) == 0) {
      disc[x] = index++;
    }
    return disc[x];
  };
  dsu d(2 * m + 1);
  int ans = 0;
  bool ok = true;
  for (int tt = 0; tt < m; tt++) {
    int x, y;
    string ops;
    cin >> x >> y >> ops;
    x = Disc(x - 1);
    y = Disc(y);
    int t = (ops == "odd") ? 1 : 0;
    if (d.is_united(x, y)) {
      if ((d.d[x] ^ d.d[y]) != t) {
        ans = tt;
        ok = false;
        break;
      }
    } else {
      d.unite(x, y, t);
    }
  }
  if (ok) {
    cout << m << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}