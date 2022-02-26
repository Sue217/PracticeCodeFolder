/**
 *    author: subobo
 *    created: 24.02.2022 23:35:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> t[i];
    }
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    vector<long long> f(n + 1), g(n + 1);
    static constexpr int inf = (int) 2e9;
    function<void(int, int)> Dfs = [&](int u, int fa) {
      int ma = 0;
      long long sum = 0;
      for (int v : e[u]) {
        if (v != fa) {
          Dfs(v, u);
          sum += f[v];
          ma = max(ma, a[v]);
        }
      }
      f[u] = sum + ma;
      pair<int, int> m1(-inf, 0), m2(-inf, 0);
      for (int v : e[u]) {
	      if (v != fa && t[v] == 3) {
	        pair<int, int> m3(a[v], v);
          if (m3 > m1) {
            m2 = m1;
            m1 = m3;
          } else
          if (m3 > m2) {
            m2 = m3;
          }
	      }
      }
      for (int v : e[u]) {
        if (v != fa) {
          long long val = sum + g[v] - f[v];
          val += (v != m1.second) ? m1.first : m2.first;
          f[u] = max(f[u], val);
        }
      }
      g[u] = sum + a[u];
    };
    Dfs(1, 0);
    cout << f[1] + a[1] << '\n';
  }
  return 0;
}
