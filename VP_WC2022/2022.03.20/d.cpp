/**
 *    author: subobo
 *    created: 20.03.2022 20:06:20
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
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    while (x != p[x]) {
      x = p[x];
    }
    return x;
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
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(n + 1);
  vector<int> enemy(n);
  for (int i = 0; i < m; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    --x; --y;
    if (op == 0) {
      d.unite(x, y);
    }
    if (op == 1) {
      if (enemy[x] == 0) {
        enemy[x] = d.get(y);
      } else {
        d.unite(enemy[x], y);
      }
      if (enemy[y] == 0) {
        enemy[y] = d.get(x);
      } else {
        d.unite(enemy[y], x);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (d.p[i] == i) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}