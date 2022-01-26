/**
 *    author: subobo
 *    created: 26.01.2022 10:17:10
**/
#include <bits/stdc++.h>
#pragma GCC optimize(2)

using namespace std;

class dsu {
 public:
  vector<int> p;
  vector<pair<int, int>> cloud;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    cloud.resize(n);
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
      cloud[y].first += cloud[x].first;
      cloud[y].second += cloud[x].second;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, V;
  cin >> n >> m >> V;
  dsu d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> d.cloud[i].first >> d.cloud[i].second;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    d.unite(u, v);
  }
  vector<int> dp(V + 1);
  for (int i = 1; i <= n; i++) {
    if (d.p[i] == i) {
      for (int j = V; j >= d.cloud[i].first; j--) {
        dp[j] = max(dp[j], dp[j - d.cloud[i].first] + d.cloud[i].second);
      }
    }
  }
  cout << dp[V] << '\n';
  return 0;
}