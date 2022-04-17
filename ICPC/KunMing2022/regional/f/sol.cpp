#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    --v; --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  double ans = 0.0;
  vector<int> point(n);
  function<long long(int, int)> Dfs = [&](int v, int pv)->long long {
    point[v] += (int) g[v].size();
    if (g[v].size() == 1) {
      return b[v];
    }
    long long mx = 0;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      point[v] += point[u];
      mx = max(mx, Dfs(u, v));
    }
    mx += b[v] * b[v] * 0.25;
    ans = max(ans, (double) mx / point[v]);
    return mx;
  };
  Dfs(0, -1);
  cout << fixed << setprecision(20) << ans << '\n';
  return 0;
}