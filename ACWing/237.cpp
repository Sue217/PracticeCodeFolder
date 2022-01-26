/**
 *    author: subobo
 *    created: 26.01.2022 22:24:21
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
    p[x] = y;
  }

  inline bool is_united(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    unordered_map<int, int> disc;
    int index = 0;
    auto Disc = [&](int x) {
      if (disc.count(x) == 0) {
        disc[x] = index++;
      }
      return disc[x];
    };
    vector<pair<int, int>> equal, diff;
    for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      x = Disc(x);
      y = Disc(y);
      if (z == 1) {
        equal.emplace_back(x, y);
      } else {
        diff.emplace_back(x, y);
      }
    }
    dsu d(index + 1);
    for (auto it : equal) {
      d.unite(it.first, it.second);
    }
    bool ok = true;
    for (auto it : diff) {
      if (d.is_united(it.first, it.second)) {
        ok = false;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}