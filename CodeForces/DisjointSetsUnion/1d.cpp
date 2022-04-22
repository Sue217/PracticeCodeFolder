/**
 *    author: subobo
 *    created: 22.04.2022 14:36:51
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
    iota(p.begin(), p.end(), 0);
    sz.resize(n);
    fill(sz.begin(), sz.end(), 1);
  }

  inline int get(int x) {
    return (x == p[x] ? x : get(p[x]));
  }

  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[x] = y;
    sz[y] += sz[x];
  }

  inline bool united(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) return false;
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dsu d(n);
  vector<tuple<string, int, int>> a;
  while (q--) {
    string op;
    cin >> op;
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    a.emplace_back(op, x, y);
  }
  reverse(a.begin(), a.end());
  vector<string> ans;
  for (int i = 0; i < (int) a.size(); i++) {
    string op = get<0>(a[i]);
    int x = get<1>(a[i]);
    int y = get<2>(a[i]);
    if (op == "ask") {
      ans.push_back(d.united(x, y) ? "YES" : "NO");
    }
    if (op == "cut") {
      d.unite(x, y);
    }
  }
  for (int i = (int) ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << '\n';
  }
  return 0;
}