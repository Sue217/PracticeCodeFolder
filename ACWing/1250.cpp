/**
 *    author: subobo
 *    created: 26.01.2022 09:44:13
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
  dsu d(n * n);
  for (int tt = 1; tt <= m; tt++) {
    int x, y;
    char op;
    cin >> x >> y >> op;
    --x; --y;
    int a = x * n + y, b;
    if (op == 'D') {
      b = (x + 1) * n + y;
    } else {
      b = x * n + y + 1;
    }
    if (!d.unite(a, b)) {
      cout << tt << '\n';
      return 0;
    }
  }
  cout << "draw" << '\n';
  return 0;
}