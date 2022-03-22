/**
 *    author: subobo
 *    created: 22.03.2022 15:32:42
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
  vector<int> p, sz;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    sz.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
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
      sz[y] += 1;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  dsu d(n);
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    a.emplace_back(x, y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j].first < a[i].first && a[j].second < a[i].second || a[j].first > a[i].first && a[j].second > a[i].second) {
        d.unite(i, j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << d.sz[d.get(i)] << '\n';
  }
  return 0;
}