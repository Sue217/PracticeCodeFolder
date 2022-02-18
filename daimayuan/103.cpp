/**
 *    author: subobo
 *    created: 18.02.2022 17:07:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(n + 1, -1), e(n + 1), ne(n + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int id = 2; id <= n; id++) {
    int fa;
    cin >> fa;
    Add(fa, id);
  }
  vector<int> v(n + 1, 0), w(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  vector<int> l(n + 1, 0), r(n + 1, 0), Id(n + 1, 0);
  int tot = 0;
  function<void(int)> Dfs = [&](int u) {
    l[u] = ++tot;
    Id[tot] = u;
    for (int id = h[u]; id != -1; id = ne[id]) {
      Dfs(e[id]);
    }
    r[u] = tot;
  };
  Dfs(1);
  vector<vector<int>> dp(n + 4, vector<int>(m + 4, 0));
  for (int i = 1; i <= m; i++) {
    dp[n + 1][i] = -(int) 2e9;
  }
  for (int i = n; i >= 1; i--) {
    int u = Id[i];
    for (int j = 0; j <= m; j++) {
      dp[i][j] = dp[r[u] + 1][j];
      if (j - w[u] >= 0) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j - w[u]] + v[u]);
      }
    }
  }
  for (int it = 0; it <= m; it++) {
    if (dp[1][it] < 0) {
      cout << 0 << '\n';
      continue;
    }
    cout << dp[1][it] << '\n';
  }
  return 0;
}