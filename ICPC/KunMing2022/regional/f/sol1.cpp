#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<double> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  double ans = -2e30;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ans = max(ans, pow(b[u] + b[v], 2) / 16);
  }
  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end(), [&](int x, int y) {
      return b[x] < b[y];
    });
    if (g[i].size() >= 2) {
      int x = g[i][0];
      int y = g[i][1];
      ans = max(ans, pow(b[x] + b[y] + b[i], 2) / 36);
      int t = (int) g[i].size();
      x = g[i][t - 1];
      y = g[i][t - 2];
      ans = max(ans, pow(b[x] + b[y] + b[i], 2) / 36);
    }
  }
  cout << fixed << setprecision(17) << ans << '\n';
  return 0;
}