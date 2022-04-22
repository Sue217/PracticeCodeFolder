#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<double> dp(n);
  bool ok = false;
  const double eps = 1e-8;
  function<void(int, int)> Dfs = [&](int v, int pv) {
    if (ok) return;
    if (g[v].size() == 1) {
      dp[v] = (double) b[v];
    }
    double mx1 = -2e30;
    double mx2 = -2e30;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      Dfs(u, v);
      if (dp[u] > mx1) {
        mx2 = mx1;
        mx1 = dp[u];
      } else
      if (dp[u] > mx2) {
        mx2 = dp[u];
      }
    }
    if (b[v] + mx1 > eps) ok = true;
    dp[v] = max(b[v], b[v] + mx1);
  };
  Dfs(0, -1);
  cout << fixed << setprecision(17) << dp[0] << '\n';
  return 0;
}