/**
 *    author: subobo
 *    created: 27.01.2022 22:18:03
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
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
  const int bias = m;
  dsu d(4 * m + bias + 1);
  int ans = 0;
  bool ok = true;
  for (int tt = 0; tt < m; tt++) {
    int x, y;
    string ops;
    cin >> x >> y >> ops;
    x = Disc(x - 1);
    y = Disc(y);
    // x, y: even
    // x + bias, y + bias: odd
    if (ops == "even") {
      if (d.get(x + bias) == d.get(y)) {
        ans = tt;
        ok = false;
        break;
      }
      d.unite(x, y);
      d.unite(x + bias, y + bias);
    } else {
      if (d.get(x) == d.get(y)) {
        ans = tt;
        ok = false;
        break;
      }
      d.unite(x, y + bias);
      d.unite(x + bias, y);
    }
  }
  if (ok) {
    cout << m << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}