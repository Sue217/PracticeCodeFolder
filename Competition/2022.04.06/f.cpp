/**
 *    author: subobo
 *    created: 06.04.2022 14:50:21
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int ans = 0;
    vector<int> deg(n);
    function<void(int, int)> Dfs = [&](int v, int pv) {
      if (v != 0) {
        deg[v] = 1;
      }
      for (int u : g[v]) {
        if (u == pv) {
          continue;
        }
        Dfs(u, v);
        deg[v] += 1;
      }
      if (deg[v] > k) {
        ans += deg[v] - k;
        if (pv != -1) {
          deg[pv] -= 1;
        }
      }
    };
    Dfs(0, -1);
    cout << ans << '\n';
  }
  return 0;
}